#include <leetcode.hpp>
#include <vector>

using namespace std;

int solution::findMin(vector<int> &nums) {
    auto solve = [&nums](auto fn, int l, int r) {
        if (l == r)
            return nums[l];

        int mid = l + (r - l) / 2;

        if (nums[mid] > nums[r])
            return fn(fn, mid + 1, r);
        else
            return fn(fn, l, mid);
    };

    return solve(solve, 0, size(nums) - 1);
};
