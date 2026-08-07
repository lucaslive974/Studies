#include "leetcode.hpp"

int solution::findMin(vector<int> &nums) {
    auto solve = [&nums](auto fn, size_t left, size_t right) -> int {
        if (left == right)
            return nums[left];

        size_t mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            return fn(fn, mid + 1, right);

        if (nums[mid] == nums[right])
            return fn(fn, left, right - 1);

        return fn(fn, left, mid);
    };

    return solve(solve, 0, size(nums) - 1);
};
