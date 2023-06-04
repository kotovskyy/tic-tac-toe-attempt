#include "TicTacToe.h"

Game::Game() : menu(nullptr) {
	init();
	menu->mainMenu(this);
}

Game::~Game() {
	delete menu;
}

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
	int computersChar = 2;
	int perm;
	std::string field_number;
	int nrow, ncol;
	showField(root->field_state);
	while (1) {
		// add some protection against choosing wrong fields
		std::cout << "Enter field number ('nrow,ncol'): ";
		std::cin >> field_number;
		nrow = std::stoi(field_number.substr(0, field_number.find(',')));
		ncol = std::stoi(field_number.substr(field_number.find(',') + 1, std::string::npos)); //field_size % 10 + 1
		root->field_state[nrow][ncol] = playersChar;
		showField(root->field_state);

		perm = isGameFinished(root->field_state);
		if (perm) {
			if (perm == 3) {
				std::cout << "IT'S A DRAW!" << std::endl;
			}
			else {
				std::cout << perm << " won the game!" << std::endl;
			}
			break;
		}

		computersTurn(root, computersChar, playersChar, true);
		showField(root->field_state);

		//std::cout << "Enter field number ('nrow,ncol'): ";
		//std::cin >> field_number;
		//nrow = std::stoi(field_number.substr(0, field_number.find(',')));
		//ncol = std::stoi(field_number.substr(field_number.find(',') + 1, std::string::npos)); //field_size % 10 + 1
		//root->field_state[nrow][ncol] = computersChar;


		perm = isGameFinished(root->field_state);
		if (perm) {
			if (perm == 3) {
				std::cout << "IT'S A DRAW!" << std::endl;
			}
			else {
				std::cout << perm << " won the game!" << std::endl;
			}
			break;
		}
	}

	// there must be:
	// 1) check, if game is not finished
	// 2) if game is finished - finish
	// 3) else - computer's move

}

void Game::playersTurn() {

}

int Game::heuristicFunc(std::vector<std::vector<int> > field) {
	int result = isGameFinished(field);
	if (result == 1) {
		return -10;
	}
	else if (result == 2) {
		return 10;
	}
	return 0;
}

void Game::buildGameTree(Node* node, const int& computersChar, const int& playerChar, bool maxPlayer) {
	if (isGameFinished(node->getField())) {
		return;
	}
	Node* child = nullptr;
	int value = maxPlayer ? computersChar : playerChar;
	bool nextPlayer = maxPlayer ? false : true;
	for (int i = 0; i < field_size; i++) {
		for (int j = 0; j < field_size; j++) {
			if (node->field_state[i][j] != 0) continue;
			node->field_state[i][j] = value;
			child = new Node(node->field_state);
			node->field_state[i][j] = 0;

			child->setParent(node);
			child->depth = node->depth + 1;
			node->addChildren(child);
			buildGameTree(child, computersChar, playerChar, nextPlayer);
		}
	}
	child = nullptr;
	//delete child;
}

void Game::computersTurn(Node* node, const int& computersChar, const int& playerChar, bool maxPlayer) {
	// 1) get current field state
	buildGameTree(node, computersChar, playerChar, maxPlayer);
	int minimaxvalue = minimax(node, -1, maxPlayer);
	std::cout << "MINIMAX RESULT: " << minimaxvalue << std::endl;
	for (int i = 0; i < node->getChildren().size(); i++) {
		if ((node->children[i] != nullptr) && (node->children[i]->heuristic_value == minimaxvalue)) {
			//node->children[i]->children.clear();
			node->field_state = node->children[i]->field_state;
			break;
		}
	}
	node->children.clear();
}


int Game::minimax(Node* current, int depth, bool maxPlayer) {
	if ((depth == 0) || isGameFinished(current->getField())) {
		// return Heuristic evaluation of current game state
		current->setValue(heuristicFunc(current->getField()));
		return current->getValue();
	}

	if (maxPlayer) {
		int maxValue = -1000;
		int value;
		for (int i = 0; i < current->getChildren().size(); i++) {
			value = minimax(current->getChildren()[i], depth - 1, false);
			maxValue = max(maxValue, value);
		}
		current->setValue(maxValue);
		return maxValue;
	}
	else {
		int minValue = 1000;
		int value;
		for (int i = 0; i < current->getChildren().size(); i++) {
			value = minimax(current->getChildren()[i], depth - 1, true);
			minValue = min(minValue, value);
		}
		current->setValue(minValue);
		return minValue;
	}
}

bool Game::isFull(std::vector<std::vector<int> > field) {
	int emptyCells = 0;

	// check for draw, if there are any empty cells left
	for (int i = 0; i < field_size; i++) {
		for (int j = 0; j < field_size; j++) {
			if (field[i][j] == 0) {
				emptyCells++;
			}
		}
	}

	if (emptyCells == 0) { return true; } // draw
	return false;
}

int Game::isGameFinished(std::vector<std::vector<int> > field) {

	if (isFull(field)) { return 3; } // draw

	int counter = 1;  // counter is 1 FROM STARTERS because first previous is -1 anyway
	int previous = -1;
	int current;

	
	// check all horizontal possibilities
	for (int i = 0; i < field_size; i++) {
		counter = 1;
		previous = -1;
		for (int j = 0; j < field_size; j++) {
			current = field[i][j];

			if (current == previous) {
				counter++;
			}
			else {
				counter = 1;
			}

			if (counter == win_length) {
				return current;
			}
			previous = current;
		}
	}

	//counter = 1;
	//previous = -1;

	// check all vertical possibilities
	for (int i = 0; i < field_size; i++) {
		counter = 1;
		previous = -1;
		for (int j = 0; j < field_size; j++) {
			current = field[j][i];

			if (current == previous) {
				counter++;
			}
			else {
				counter = 1;
			}
			if (counter == win_length) {
				return current;
			}
			previous = current;
		}
	}

	//counter = 1;
	//previous = -1;
	int row, col;

	// =============== angle < 90 ========================
	for (int i = field_size - 1; i >= (win_length - 1); i--) {
		row = i;
		col = 0;
		counter = 1;
		previous = -1;
		while ((row >= 0) && (col < field_size)) {
			current = field[row][col];

			if ((current == previous) && (current != 0)) {
				counter++;
			}
			else {
				counter = 1;
			}
			if (counter == win_length) {
				return current;
			}
			previous = current;
			row--;
			col++;
		}

	}

	for (int i = 1; i < field_size; i++) {
		row = i;
		col = field_size - 1;
		counter = 1;
		previous = -1;
		while ((row < field_size) && (col >= 0)) {
			current = field[row][col];

			if ((current == previous) && (current != 0)) {
				counter++;
			}
			else {
				counter = 1;
			}
			if (counter == win_length) {
				return current;
			}
			previous = current;
			row++;
			col--;
		}
	}
	// ===============================================

	//counter = 1;
	//previous = -1;

	// =============== angle > 90 ====================

	for (int i = field_size - 1; i >= (win_length-1); i--) {
		row = i;
		col = field_size-1;
		counter = 1;
		previous = -1;
		while ((row >= 0) && (col >= 0)) {
			current = field[row][col];

			if ((current == previous) && (current != 0)) {
				counter++;
			}
			else {
				counter = 1;
			}
			if (counter == win_length) {
				return current;
			}
			previous = current;
			row--;
			col--;
		}

	}

	for (int i = 1; i < field_size; i++) {
		row = i;
		col = 0;
		counter = 1;
		previous = -1;
		while ((row < field_size) && (col >= 0)) {
			current = field[row][col];

			if ((current == previous) && (current != 0)) {
				counter++;
			}
			else {
				counter = 1;
			}
			if (counter == win_length) {
				return current;
			}
			previous = current;
			row++;
			col++;
		}
	}
	// ===============================================


	return 0; // game is not finished yet
}



void Game::showField(std::vector<std::vector<int> > field) {
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


