#include <iostream>

#include "src/hello.hpp"

int main() {
    Squirrel cheeks     = Squirrel("Cheeks");
    Node node_one       = Node(&cheeks);

    Squirrel squeaks    = Squirrel("Squeaks");
    Node node_two       = Node(&squeaks);

    Squirrel fluffybutt = Squirrel("Mr. Fluffy Butt");
    Node node_three     = Node(&fluffybutt);

    node_one.set_left(&node_two);
    node_one.set_right(&node_three);

    Node* retrieved_node_one = node_one.left();
    Node* retrieved_node_two = node_one.right();

    std::cout << "Root:  " << node_one.get_data()->get_name()       << std::endl;
    std::cout << "Left:  " << retrieved_node_one->get_data()->get_name() << std::endl;
    std::cout << "Right: " << retrieved_node_two->get_data()->get_name() << std::endl;

    return 0;
}
