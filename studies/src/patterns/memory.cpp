#include "patterns.hpp"
#include "utils.hpp"
#include <initializer_list>
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

#include <cstring>
#include <ranges>

class Vector {
  public:
    Vector(size_t size = 4, std::string id = "vec") : data(new int[size]), size(size), idName(id) {}

    Vector(std::initializer_list<int> init) : Vector(init.size()) {
        for (auto [idx, val] : std::views::enumerate(init)) {
            insert(idx, val);
        }
    }

    //Copy constructor
    Vector(const Vector &other) : Vector(other.size, other.idName) {
        idName += "_copy_constructor";
        memcpy(data, other.data, sizeof(int) * size);
    }

    //Move constructor
    Vector(Vector &&other) noexcept {
        idName = other.idName;
        idName += "_move_constructor";
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;
    }

    //Copy assignment
    Vector &operator=(const Vector &other) {
        if (this == &other)
            return *this;
        delete[] data;

        size = other.size;
        data = new int[other.size];
        idName = other.idName + "_copy_assign";
        memcpy(data, other.data, sizeof(int) * size);

        return *this;
    };

    //Move assignment
    Vector &operator=(Vector &&other) noexcept {
        if (this == &other)
            return *this;

        delete[] data;

        idName = other.idName + "_move_assign";
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        return *this;
    }

    ~Vector() {
        std::cout << std::format("Deleting vector id: {}\n", idName);
        delete[] data;
    }

    void insert(size_t idx, int value) {
        idx = idx % size;
        data[idx] = value;
    }

    void printData() {
        if (data == nullptr) {
            std::cout << "Moved vector: This one is empty\n";
            return;
        }
        for (auto idx : std::views::iota(0UZ, size)) {
            std::cout << std::format("{} ", data[idx]);
        }
        std::cout << '\n';
    }

  private:
    std::string idName;
    int *data;
    size_t size;
};

void ruleOfFive() {
    // Initialize
    Vector vec{2, 4, 6, 8, 10};

    // Copy assignment;
    Vector vec2;
    vec2 = vec;
    vec2.insert(4, 8); // Modify last value;

    std::cout << "Vec original: ";
    vec.printData();

    std::cout << "Vec copy:     ";
    vec2.printData();

    {
        // Move assignment;
        auto vecMove = std::move(vec);

        // Vector empty;
        vec.printData();

        std::cout << "New moved vector: ";
        vecMove.printData();
    } // New vec is destroyed
} // All other vecs are destroyed, including the moved one
