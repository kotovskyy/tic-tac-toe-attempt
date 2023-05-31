#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <string>
#include "TicTacToe.h"

class Game;
class Menu{
private:
	void sayBye();
	void printMenu();
	void printSettingsMenu(Game *game);
	void setFieldSize(Game* game);
	void setWinLength(Game* game);
public:
	Menu();
	void mainMenu(Game* game);
	void settingsMenu(Game* game);
};

#endif // !MAINMENU_H
