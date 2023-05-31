#pragma once
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include "mainMenu.h"

class Menu;

class Game {
private:
	int field_size;
	int win_length;
	void init();
	Menu* menu;
	friend class Menu;
	void startGame();
public:
	Game();
	~Game();
	//void setFieldSize(int field_size);
	//void setWinLength(int win_length);
	//int getFieldSize();
	//int getWinLength();
};

#endif // !TIC_TAC_TOE_H
