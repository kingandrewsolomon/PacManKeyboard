#pragma once
#include "pch.h"
#include "Board.h"
#include "Player.h"
#include "Ghost.h"
#include <LogitechLEDLib.h>

class GameController
{
public:
	GameController(Board *, Player *, Ghost*);
	void runGame();
	void initializeBoard();
	void loadPlayer();
	void loadGhost();
	~GameController();

private:
	Board *board;
	Player *player;
	Ghost *ghost;
	void update();
	void draw_board();
	void draw_player();
	void move_player(int);
	void draw_ghost();
	int get_keypress();
};