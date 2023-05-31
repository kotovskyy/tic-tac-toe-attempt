#include "TicTacToe.h"

Game::Game() : menu(nullptr) {
	init();
	menu->mainMenu(this);
}

Game::~Game() {}

void Game::init(){
	this->field_size = 3;
	this->win_length = 3;
	this->menu = new Menu();
}

void Game::startGame() {
	std::cout << "=====================================================" << std::endl;
	std::cout << "            GAME HAS STARTED! GOOD LUCK!             " << std::endl;
	std::cout << "=====================================================" << std::endl;
	int playersChar = 1; // 0 - nothing, 1 - X, 2 - O
	bool gameFinished = false;
	std::string field_number;
	int nrow, ncol;
	while (!gameFinished) {
		showField();
		std::cout << "Enter field number ('nrow,ncol'): ";
		std::cin >> field_number;
		nrow = std::stoi(field_number.substr(0, field_number.find(',')));
		ncol = std::stoi(field_number.substr(field_number.find(',')+1, field_size%10+1));
		
		field[nrow][ncol] = playersChar;
	}
}

void Game::showField() {
	std::string hborder = "  " + std::string(4 * field_size + 1, '-');
	std::cout << "  ";
	for (int i = 0; i < field_size; i++) {
		std::cout << "  " << i << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < field_size; i++) {
		std::cout << hborder << std::endl;
		std::cout << i <<" ";
		for (int j = 0; j < field_size; j++) {
			std::string value;
			if (field[i][j] == 0) {
				//value = std::to_string((i+1)*(j+1));
				value = " ";
			}
			else if (field[i][j] == 1) {
				value = "X";
			}
			else if (field[i][j] == 2) {
				value = "O";
			}
			std::cout <<"| " << value << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << hborder << std::endl;
}


