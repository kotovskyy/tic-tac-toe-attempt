#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>

class Menu{
private:

public:
	Menu();
	Menu(int field_size, int win_length);
	void mainMenu();
	void settingsMenu();
};

#endif // !MAINMENU_H
