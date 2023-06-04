#pragma once
#ifndef NODE_H
#define NODE_H
#include <vector>

class Game;

class Node {
private:
	std::vector<std::vector<int> > field_state;
	int heuristic_value;
	int depth;
	Node* parent;
	std::vector<Node*> children;
	friend class Game;
public:
	Node();
	Node(std::vector<std::vector<int> > field_state);
	void addChildren(const std::vector<std::vector<int> >& field_state);
	void addChildren(Node* child);
	void setParent(Node* p);
	void setValue(const int& value);
	int getValue();
	std::vector<Node*> getChildren();
	std::vector<std::vector<int> > getField();
};

#endif // !NODE_H
