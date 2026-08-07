#include "leetcode.hpp"

int solution::getCommon(vector<int> &nums1, vector<int> &nums2) {
    auto first = nums1.begin(), second = nums2.begin();
    while (first != nums1.end() && second != nums2.end()) {
        auto first_val = *first, second_val = *second;
        if (first_val == second_val)
            return first_val;

        if (first_val < second_val)
            first++;
        else
            second++;
    }

    return -1;
};
