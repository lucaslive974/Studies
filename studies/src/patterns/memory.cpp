#include "patterns.hpp"
#include "utils.hpp"
#include <iostream>
#include <memory>

struct SmartDataType {
    std::array<int, 4> data;

    SmartDataType() : data{1, 2, 3, 4} {}
    SmartDataType(int a, int b, int c, int d) : data{a, b, c, d} {}
};

void printSmartDataType(std::shared_ptr<SmartDataType> obj) {
    std::cout << "SmartDataType as shared_ptr parameter: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << obj->data[i] << ' ';
    }
    std::cout << '\n' << "Inside function callee - ptr1 use count: " << obj.use_count() << '\n';
}

void printSmartDataType(std::unique_ptr<SmartDataType> obj) {
    std::cout << "SmartDataType: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << obj->data[i] << ' ';
    }
    std::cout << '\n';
}

void smartPointers() {
    std::cout << "Shared Pointer Example" << '\n';
    utils::printLineSpacing();

    auto ptr1 = std::make_shared<SmartDataType>();
    std::cout << "ptr1 use count: " << ptr1.use_count() << '\n';
    printSmartDataType(ptr1);
    std::cout << "ptr1 use count: " << ptr1.use_count() << '\n';

    utils::printLineSpacing();

    std::cout << "Unique Pointer Example" << '\n';
    utils::printLineSpacing();
    auto ptr2 = std::make_unique<SmartDataType>(5, 6, 7, 8);
    printSmartDataType(std::move(ptr2));
}

void memory() {}
