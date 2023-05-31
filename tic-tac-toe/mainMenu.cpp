#include "mainMenu.h"


Menu::Menu() {

}

Menu::Menu(int field_size, int win_length) {

}

void Menu::mainMenu() {
	// by the way, can add field 'name' and say 'hello dear "name"!'
	std::cout << "=====================================================" << std::endl;
	std::cout << "HELLO DEAR PLAYER! ARE YOU READY TO PLAY TIC-TAC-TOE?" << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << "1. Yes, I'm ready!                (START)" << std::endl;
	std::cout << "2. Wait, I've to change something (SETTINGS)" << std::endl;
	std::cout << "3. Sorry, not now...              (EXIT)" << std::endl;
	std::cout << "=====================================================" << std::endl;
}

void Menu::settingsMenu() {

}