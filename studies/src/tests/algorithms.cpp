#include "algorithms.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

using namespace algorithms;

template <typename T, typename Fn> void applySorting(std::string algName, std::vector<T> vec, Fn fn) {
    int operations = 0;

    auto vecDesc = vec;
    auto vecAsc = vec;

    std::cout << std::format("[{}]", algName) << '\n';
    std::cout << "Original vector: ";
    utils::printVector(vec);

    operations = fn(vecAsc, sorting::Less<T>{});
    std::cout << "Sorted non descendent: ";
    utils::printVector(vecAsc);
    std::cout << std::format("Number of operations [{}]: ", algName) << operations << '\n';

    operations = fn(vecDesc, sorting::Greater<T>{});
    std::cout << "Sorted non ascendent: ";
    utils::printVector(vecDesc);
    std::cout << std::format("Number of operations [{}]: ", algName) << operations << '\n';
}

void mergeSorting(std::vector<int> vec) {
    applySorting("Merge Sort", vec, [](auto &v, auto cmp) { return sorting::mergeSort(v, cmp); });
};

void bubbleSorting(std::vector<int> vec) {
    applySorting("Bubble Sort", vec, [](auto &v, auto cmp) { return sorting::bubbleSort(v, cmp); });
};

void sortingWrapper() {
    std::vector<int> vec{4, 9, 1, 8, 4, 3, 10, 6, 19, 7, 11, 2};
    mergeSorting(vec);
    utils::printLineSpacing();
    bubbleSorting(vec);
};

void fastExponentiating() {
    unsigned int res1 = numeric::fastExponentiation(2, 10);
    std::cout << "2¹⁰=" << res1 << '\n';

    unsigned int res2 = numeric::fastExponentiation(4, 2);
    std::cout << "4²=" << res2 << '\n';

    unsigned int res3 = numeric::fastExponentiation(3, 3);
    std::cout << "3³=" << res3 << '\n';
}

int main(int argc, char **argv) {
    std::cout << "Algorithms Examples" << '\n';

    std::vector<std::pair<std::string, utils::PatternFunction>> algorithms = {{"Sorting", sortingWrapper},
                                                                              {"Fast Exponentiation", fastExponentiating}};

    for (const auto &algorithm : algorithms) {
        utils::executePattern(algorithm.first, algorithm.second);
    }

    return 0;
}