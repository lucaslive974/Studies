#pragma once

#include <iostream>
#include <vector>

namespace utils {
void printLineSpacing() { std::cout << "===================" << "\n\n"; }

template <typename T> void printVector(std::vector<T> &vec) {
    for (auto val : vec) {
        std::cout << val << " ";
    }

    std::cout << '\n';
}
} // namespace utils