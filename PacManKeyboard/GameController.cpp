#include "pch.h"
#include <cstdlib>
#include "windows.h"
#include <iostream>
#include "GameController.h"

GameController::GameController(Board *b, Player *p, Ghost *g)
{
	board = b;
	player = p;
	ghost = g;
}

void GameController::initializeBoard()
{
	board = new Board();
	board->initializeBoard();
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
	int direction = 1;
	while (player->lives > 0) {
		int temp = get_keypress();
		if (temp > 0 && temp < 5)
			direction = temp;
		std::cout << "temp: " << temp << std::endl;
		std::cout << "direction: " << direction << std::endl;
		move_player(direction);
		
		draw_board();
		draw_player();
		draw_ghost();
		Sleep(250);
	}
}

int GameController::get_keypress()
{
	short up = 1 * GetAsyncKeyState(VK_UP);
	short right = 2 * GetAsyncKeyState(VK_RIGHT);
	short down = 3 * GetAsyncKeyState(VK_DOWN);
	short left = 4 * GetAsyncKeyState(VK_LEFT);

	return up + right + down + left;
}

void GameController::loadPlayer() 
{
	int y = rand() % board->rows;
	int x = rand() % board->lengths[y];

	player = new Player(x, y);
}

void GameController::loadGhost()
{
	int y = rand() % board->rows;
	int x = rand() % board->lengths[y];

	ghost = new Ghost(x, y);
}

void GameController::draw_board()
{
	for (int i = 0; i < board->rows; i++)
	{
		for (int j = 0; j < board->lengths[i]; j++)
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
	std::cout << "x: " << player->xpos << std::endl;
	std::cout << "y: " << player->ypos << std::endl;
	LogiLedSetLightingForKeyWithKeyName(board->GameBoard[player->ypos][player->xpos], 100, 50, 0);
}

void GameController::draw_ghost()
{
	LogiLedSetLightingForKeyWithKeyName(board->GameBoard[ghost->ypos][ghost->xpos], 100, 0, 0);
}

void GameController::move_player(int direction)
{
	switch (direction)
	{
	case 1:
		if (player->ypos - 1 < 0)
			player->ypos = this->board->rows;
		break;
	case 2:
		if (player->xpos + 1 == this->board->lengths[player->ypos])
			player->xpos = -1;
		break;
	case 3:
		if (player->ypos + 1 == this->board->rows)
			player->ypos = -1;
		break;
	case 4:
		if (player->xpos - 1 < 0)
			player->xpos = this->board->lengths[player->ypos];
		break;
	}

	player->move(direction);
	board->points[player->ypos][player->xpos] = 0;
}

GameController::~GameController()
{
	delete player;
	delete ghost;
	delete board;
}