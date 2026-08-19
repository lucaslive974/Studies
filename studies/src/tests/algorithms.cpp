#include "algorithms.hpp"
#include <iostream>

using namespace algorithms;

int main(int argc, char **argv) {
    std::vector<int> vec{4, 9, 1, 8, 4, 3};
    sorting::mergeSort(vec);

    int res = numeric::fastExponentiation(2, 10);
    std::cout << "Fast expo: 2¹⁰=" << res << '\n'; 

    return 0;
}