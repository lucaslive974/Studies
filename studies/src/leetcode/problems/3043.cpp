#include "leetcode.hpp"
#include <math.h>
#include <string>
#include <unordered_set>

int solution::longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    unordered_set<int> prefixes;

    for (auto val : arr1)
        while (val > 0) {
            prefixes.insert(val);
            val /= 10;
        }

    int longest_prefix = 0;
    for (auto val : arr2) {
        while (val > 0) {
            if (!prefixes.contains(val)) {
                val /= 10;
                continue;
            }

            int digits = to_string(val).size();
            longest_prefix = max(digits, longest_prefix);
            break;
        }
    }

    return longest_prefix;
};
