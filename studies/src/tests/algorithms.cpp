#include "algorithms.hpp"

using namespace algorithms;

int main(int argc, char **argv) {
    std::vector<int> vec{4, 9, 1, 8, 4, 3};
    sorting::mergeSort(vec);

    return 0;
}