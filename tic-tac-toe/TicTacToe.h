#pragma once
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include "mainMenu.h"
#include <vector>

class Menu;

class Game {
private:
	int field_size;
	int win_length;
	Menu* menu;
	std::vector<std::vector<int> > field;
	friend class Menu;
private:
	void startGame();
	void init();
	void showField();
public:
	Game();
	~Game();
};

#endif // !TIC_TAC_TOE_H
