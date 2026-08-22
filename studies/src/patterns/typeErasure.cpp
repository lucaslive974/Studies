#include "typeErasure.hpp"
#include "patterns.hpp"
#include <iostream>
#include <string>
#include <vector>

void printName(std::vector<Object> vec) { // (7)
    for (auto v : vec)
        std::cout << v.getName() << '\n';
}

struct Bar {
    [[nodiscard]] std::string getName() const { // (8)
        return "Bar";
    }
};

struct Foo {
    [[nodiscard]] std::string getName() const { // (8)
        return "Foo";
    }
};

void typeErasure() {
    std::vector<Object> vec{Object(Foo()), Object(Bar())}; // (1)
    printName(vec);
}