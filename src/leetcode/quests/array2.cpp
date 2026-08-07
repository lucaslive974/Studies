#include "leetcode.hpp"
#include <ranges>
#include <unordered_set>

vector<int> quests::array2::findDisappeardNumbers(vector<int> &nums) {
    vector<int> foundNumbers(size(nums) + 1, 0);

    for (auto &n : nums)
        foundNumbers[n] = 1;

    vector<int> ans;
    for (auto i : views::iota(1uz, size(nums) + 1))
        if (!foundNumbers[i])
            ans.push_back(i);

    return ans;
};
