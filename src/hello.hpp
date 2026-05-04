#ifndef HELLO_HPP
#define HELLO_HPP

#include <string>

class Squirrel {
private:
    std::string name;

public:
    Squirrel(std::string name);
    std::string get_name();
};

class Node {
private:
    Squirrel* data;
    Node* left_child;
    Node* right_child;

public:
    Node(Squirrel* squirrel);

    Squirrel* get_data();

    void set_left(Node* node);
    void set_right(Node* node);

    Node* left();
    Node* right();
};

#endif