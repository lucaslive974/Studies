#include "leetcode.hpp"

#include <bit>

int solution::numberOfSpecialCharsII(string word) {
    unsigned int lower_mask = 0, higher_mask = 0;

    for (auto c : word) {
        unsigned higher_bit = 1 << (toupper(c) - 'A'), lower_bit = 1 << (tolower(c) - 'a');

        if (islower(c)) {
            if (!(higher_mask & higher_bit))
                lower_mask |= lower_bit;
            else
                lower_mask &= ~lower_bit;
        }

        if (isupper(c))
            higher_mask |= higher_bit;
    }

    return popcount(lower_mask & higher_mask);
}
