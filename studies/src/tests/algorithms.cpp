#include "algorithms.hpp"
#include <iostream>

using namespace algorithms;

int main(int argc, char **argv) {
    std::vector<int> vec{4, 9, 1, 8, 4, 3};
    sorting::mergeSort(vec);

    std::cout << "Power of two expo: 2¹⁰=" << numeric::fastExponentiation(2, 10) << '\n';
    std::cout << "Power of two expo: 4²=" << numeric::fastExponentiation(4, 2) << '\n';
    std::cout << "Fast exponentiation: 3³=" << numeric::fastExponentiation(3, 3) << '\n';

    return 0;
}