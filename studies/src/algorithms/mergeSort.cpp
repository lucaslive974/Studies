#include "algorithms.hpp"

void algorithms::sorting::mergeSort(std::vector<int> &vec) {
    if (vec.size() <= 1)
        return;

    auto split = [&vec](auto self, int start, int end) -> std::vector<int> {
        if (end - start == 1)
            return {vec[start]};

        auto middle = start + ((end - start) / 2);

        auto left = self(self, start, middle);
        auto right = self(self, middle, end);

        auto leftIt = left.begin();
        auto rightIt = right.begin();

        std::vector<int> result;
        while (leftIt != left.end() && rightIt != right.end()) {
            if (*leftIt < *rightIt) {
                result.push_back(*leftIt);
                ++leftIt;
            } else {
                result.push_back(*rightIt);
                ++rightIt;
            }
        }

        while (leftIt != left.end()) {
            result.push_back(*leftIt);
            ++leftIt;
        }

        while (rightIt != right.end()) {
            result.push_back(*rightIt);
            ++rightIt;
        }

        return result;
    };

    vec = split(split, 0, vec.size());
};