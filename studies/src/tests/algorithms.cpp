#include "algorithms.hpp"
#include <iostream>

using namespace algorithms;

int main(int argc, char **argv) {
    std::vector<int> vec{4, 9, 1, 8, 4, 3};
    sorting::mergeSort(vec);

    unsigned int res1 = numeric::fastExponentiation(2, 10) << '\n';
    std::cout << "2¹⁰=" << res1 << '\n';

    unsigned int res2 = numeric::fastExponentiation(4, 2) << '\n';
    std::cout << "4²=" << res2 << '\n';

    unsigned int res3 = numeric::fastExponentiation(3, 3) << '\n';
    std::cout << "3³=" << res3 << '\n';

    return 0;
}