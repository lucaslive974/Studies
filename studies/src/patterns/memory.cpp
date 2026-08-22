#include "patterns.hpp"
#include "utils.hpp"
#include <cstring>
#include <iostream>
#include <memory>

struct CustomDataType {
    int *data;

    CustomDataType() {
        data = new int[4];
        data[0] = 1, data[1] = 2, data[2] = 3, data[3] = 4;
    };

    CustomDataType(int a, int b, int c, int d) {
        data = new int[4];
        data[0] = a, data[1] = b, data[2] = c, data[3] = d;
    }

    CustomDataType(CustomDataType &&other) noexcept {
        std::cout << "Move constructor called" << '\n';
        std::memcpy(data, other.data, sizeof(int) * 4);
        other.data = nullptr;
    }

    CustomDataType(const CustomDataType &other) {
        std::cout << "Copy constructor called" << '\n';
        std::memcpy(data, other.data, sizeof(int) * 4);
    }

    ~CustomDataType() {
        std::cout << "Destructor called" << '\n';
        delete[] data;
    }
};

void printCustomDataType(std::shared_ptr<CustomDataType> obj) {
    std::cout << "CustomDataType as shared_ptr parameter: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << obj->data[i] << ' ';
    }
    std::cout << '\n' << "Inside function callee - ptr1 use count: " << obj.use_count() << '\n';
}

void printCustomDataType(std::unique_ptr<CustomDataType> obj) {
    std::cout << "CustomDataType: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << obj->data[i] << ' ';
    }
    std::cout << '\n';
}

void smartPointers() {
    std::cout << "Shared Pointer Example" << '\n';
    utils::printLineSpacing();

    auto ptr1 = std::make_shared<CustomDataType>();
    std::cout << "ptr1 use count: " << ptr1.use_count() << '\n';
    printCustomDataType(ptr1);
    std::cout << "ptr1 use count: " << ptr1.use_count() << '\n';

    utils::printLineSpacing();

    std::cout << "Unique Pointer Example" << '\n';
    utils::printLineSpacing();
    auto ptr2 = std::make_unique<CustomDataType>(5, 6, 7, 8);
    printCustomDataType(std::move(ptr2));
}

void memory() {}
