#pragma once
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include "mainMenu.h"
#include "Node.h"
#include <vector>
#include <alg.h>

class Menu;

class Game {
private:
	int field_size;
	int win_length;
	Node* root;
	Menu* menu;
	//std::vector<std::vector<int> > field;
	friend class Menu;
	int heuristicFunc(std::vector<std::vector<int> > field);
private:
	void startGame();
	void init();
	void showField(std::vector<std::vector<int> > field);
	int isGameFinished(std::vector<std::vector<int> > field);
	void playersTurn();
	void buildGameTree(Node* node, const int& computersChar, const int& playerChar, bool maxPlayer);
	bool isFull(std::vector<std::vector<int> > field);
	int minimax(Node* current, int depth, bool maxPlayer);
	void computersTurn(Node* node, const int& computersChar, const int& playerChar, bool maxPlayer);
public:
	Game();
	~Game();
};

#endif // !TIC_TAC_TOE_H
