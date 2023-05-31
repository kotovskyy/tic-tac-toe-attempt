#include "TicTacToe.h"

Game::Game() : menu(nullptr) {
	init();
	menu->mainMenu(this);
}

Game::~Game() {

}
void Game::init(){
	this->field_size = 3;
	this->win_length = 3;
	this->menu = new Menu();
}

void Game::startGame() {
	std::cout << "started game from game class" << std::endl;
}

//void Game::setFieldSize(int field_size) { this->field_size = field_size;  }
//
//void Game::setWinLength(int win_length) { this->win_length = win_length; }
//
//int Game::getFieldSize() { return this->field_size; }
//
//int Game::getWinLength() { return this->field_size; }
