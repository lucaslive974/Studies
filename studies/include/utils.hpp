#pragma once
#include <iostream>
#include <vector>

namespace utils {
void printLineSpacing() { std::cout << "======================================" << "\n"; }

template <typename T> void printVector(std::vector<T> &vec) {
    for (auto val : vec) {
        std::cout << val << " ";
    }

    std::cout << '\n';
}

using PatternFunction = void (*)();

void executePattern(const std::string &patternName, PatternFunction patternFunction) {
    utils::printLineSpacing();
    std::cout << std::format("[{}]", patternName) << "\n";
    utils::printLineSpacing();
    patternFunction();
    utils::printLineSpacing();
    std::cout << '\n';
}

} // namespace utils