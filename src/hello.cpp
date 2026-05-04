#include "hello.hpp"

Squirrel::Squirrel(std::string name) {
   this->name = name;
}

std::string Squirrel::get_name() {
   return this->name;
}

Node::Node(Squirrel* squirrel) {
   this->data        = squirrel;
   this->left_child  = nullptr;
   this->right_child = nullptr;
}

Squirrel* Node::get_data() {
   return this->data;
}

void Node::set_left(Node* node) {
   this->left_child = node;
}

void Node::set_right(Node* node) {
   this->right_child = node;
}

Node* Node::left() {
   return this->left_child;
}

Node* Node::right() {
   return this->right_child;
}