#include "Node.h"

Node::Node() {

}
Node::Node(std::vector<std::vector<int> > field_state) {
	this->parent = nullptr;
	this->field_state = field_state;
	this->children = std::vector<Node*>();
}

void Node::addChildren(const std::vector<std::vector<int> >& field_state) {

}

void Node::addChildren(Node* child) {
	this->children.push_back(child);
}
void Node::setParent(Node* p) {
	this->parent = p;
}

std::vector<Node*> Node::getChildren() {
	return this->children;
}

std::vector<std::vector<int> > Node::getField() {
	return this->field_state;
}

void Node::setValue(const int& value) {
	this->heuristic_value = value;
}

int Node::getValue() {
	return this->heuristic_value;
}