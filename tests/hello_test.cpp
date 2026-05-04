#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE("Squirrel returns its name", "[squirrel]") {
    Squirrel s("Cheeks");
    REQUIRE(s.get_name() == "Cheeks");
}

TEST_CASE("Node children are null by default", "[node]") {
    Squirrel s("Cheeks");
    Node node(&s);
    REQUIRE(node.left()  == nullptr);
    REQUIRE(node.right() == nullptr);
}

TEST_CASE("Node stores squirrel and links children", "[node]") {
    Squirrel root_s("Cheeks"), left_s("Squeaks"), right_s("Mr. Fluffy Butt");
    Node root(&root_s), left_node(&left_s), right_node(&right_s);

    root.set_left(&left_node);
    root.set_right(&right_node);

    REQUIRE(root.get_data()->get_name()  == "Cheeks");
    REQUIRE(root.left()->get_data()->get_name()  == "Squeaks");
    REQUIRE(root.right()->get_data()->get_name() == "Mr. Fluffy Butt");
}

TEST_CASE("Can traverse two levels deep", "[node][traversal]") {
    Squirrel a("A"), b("B"), c("C");
    Node root(&a), mid(&b), leaf(&c);

    root.set_left(&mid);
    mid.set_left(&leaf);

    REQUIRE(root.left()->left()->get_data()->get_name() == "C");
}