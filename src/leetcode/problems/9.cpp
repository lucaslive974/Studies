#include "leetcode.hpp"
#include <string>

bool solution::isPalindrome(int x) {
    std::string s1 = std::to_string(x);

    int p1 = 0, p2 = s1.size();
    while (p1 < p2) {
        if (s1[p1++] != s1[p2--])
            return false;
    }

    return true;
}
