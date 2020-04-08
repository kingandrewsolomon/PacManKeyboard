#include "pch.h"
#include "GameController.h"

GameController::GameController(Board *b, Player *p, Ghost *g)
{
	board = b;
	player = p;
	ghost = g;
	game_speed = 500;
}

void GameController::initializeBoard()
{
	board = new Board();
	loadPlayer();
	draw_player();

	loadGhost();
	draw_ghost();
}

void GameController::runGame() 
{
	this->update();
}

void GameController::update() 
{
	while (player->lives > 0) 
	{
		player->direction = get_keypress();
		move_player();
		move_ghost(player->xpos, player->ypos);
		
		draw_board();
		draw_player();
		draw_ghost();
		check_status();
		Sleep(game_speed);
	}
}

int GameController::get_keypress()
{
	if (GetKeyState(VK_UP) & 0x8000) {
		return 1;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000) {
		return 2;
	}
	if (GetKeyState(VK_DOWN) & 0x8000) {
		return 3;
	}
	if (GetKeyState(VK_LEFT) & 0x8000) {
		return 4;
	}
	return player->direction;
	
}

void GameController::loadPlayer() 
{
	int y = 1;
	int x = 1;

	if (!player)
		player = new Player(x, y);
	else
	{
		player->xpos = x;
		player->ypos = y;
	}
}

void GameController::loadGhost()
{
	int y = 3;
	int x = 6;

	if(!ghost)
		ghost = new Ghost(x, y);
	else
	{
		ghost->xpos = x;
		ghost->ypos = y;
	}
}

void GameController::draw_board()
{
	for (int i = 0; i < board->rows; i++)
	{
		for (int j = 0; j < board->lengths; j++)
		{
			if(board->points[i][j] == 1)
				LogiLedSetLightingForKeyWithKeyName(board->GameBoard[i][j], 100, 100, 100);
			else
				LogiLedSetLightingForKeyWithKeyName(board->GameBoard[i][j], 0, 0, 0);
		}
	}
}

void GameController::draw_player()
{
	for (int i = 0; i < player->lives; i++)
	{
		LogiLedSetLightingForKeyWithKeyName(player->livesDisplay[i], 100, 50, 0);
	}
	LogiLedSetLightingForKeyWithKeyName(board->GameBoard[player->ypos][player->xpos], 100, 50, 0);
}

void GameController::draw_ghost()
{
	LogiLedSetLightingForKeyWithKeyName(board->GameBoard[ghost->ypos][ghost->xpos], 100, 0, 0);
}

void GameController::move_player()
{
	switch (player->direction)
	{
	case 1:
		if (player->ypos - 1 < 0)
			player->ypos = this->board->rows;
		break;
	case 2:
		if (player->xpos + 1 == this->board->lengths)
			player->xpos = -1;
		break;
	case 3:
		if (player->ypos + 1 == this->board->rows)
			player->ypos = -1;
		break;
	case 4:
		if (player->xpos - 1 < 0)
			player->xpos = this->board->lengths;
		break;
	}

	player->move();
	board->points[player->ypos][player->xpos] = 0;
}

void GameController::move_ghost(int playerX, int playerY)
{
	ghost->set_direction(playerX, playerY);

	switch (ghost->direction)
	{
	case 1:
		if (ghost->ypos - 1 < 0)
			ghost->ypos = this->board->rows;
		break;
	case 2:
		if (ghost->xpos + 1 == this->board->lengths)
			ghost->xpos = -1;
		break;
	case 3:
		if (ghost->ypos + 1 == this->board->rows)
			ghost->ypos = -1;
		break;
	case 4:
		if (ghost->xpos - 1 < 0)
			ghost->xpos = this->board->lengths;
		break;
	}
	ghost->move();
}

void GameController::check_status()
{
	// if level completed
	if (!board->hasPoints())
	{
		board->completed(player->xpos, player->ypos);
		game_speed -= 50;
		initializeBoard();
		return;
	}
	//player died
	if (player->xpos == ghost->xpos && player->ypos == ghost->ypos)
	{
		board->clear();
		board->flash(player->xpos, player->ypos, 500, 50);
		player->died();
		loadPlayer();
		loadGhost();
	}
}

GameController::~GameController()
{
	delete player;
	delete ghost;
	delete board;
}