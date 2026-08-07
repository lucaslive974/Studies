#include "leetcode.hpp"
#include <ranges>

vector<int> solution::leftRightDifference(vector<int> &nums) {
    int left = 0, right = 0, n = size(nums);
    vector<int> leftSide(n), rightSide(n);

    for (auto [i, n] : nums | views::enumerate) {
        leftSide[i] = left;
        left += n;
    }

    for (auto [i, n] : nums | views::enumerate | views::reverse) {
        rightSide[i] = right;
        right += n;
    }

    auto solve_view = views::zip(leftSide, rightSide) | views::transform([](auto a) {
                          auto [left, right] = a;
                          return abs(left - right);
                      });

    return ranges::to<vector<int>>(solve_view);
};
