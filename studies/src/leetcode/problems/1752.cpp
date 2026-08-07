#include "leetcode.hpp"
#include <ranges>

bool solution::check(vector<int> &nums) {
    int n = size(nums), local_max = n;
    for (auto [i, pair] : nums | views::adjacent<2> | views::enumerate) {
        const auto &[curr, next] = pair;
        if (next < curr) {
            local_max = i;
            break;
        }
    }

    if (local_max == n)
        return true;

    for (auto [curr, next] : nums | views::drop(local_max + 1) | views::adjacent<2>) {
        if (next < curr)
            return false;
    }

    if (nums.back() > nums.front())
        return false;

    return true;
};
