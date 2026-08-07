#include "leetcode.hpp"
#include <bit>

int solution::numberOfSpecialChars(string word) {
    unsigned int lower_mask = 0, upper_mask = 0;

    for (auto c : word) {
        if (islower(c))
            lower_mask |= (1 << (c - 'a'));
        else
            upper_mask |= (1 << (c - 'A'));
    }

    return popcount(upper_mask & lower_mask);
};
