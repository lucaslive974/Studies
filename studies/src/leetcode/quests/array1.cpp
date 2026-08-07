#include "leetcode.hpp"
#include <algorithm>
#include <ranges>
#include <vector>

using namespace std;

vector<int> quests::array1::getConcatenation(vector<int> &nums) {
    vector<int> ans;

    for (auto _ : views::iota(1, 2))
        ans.insert(ans.end(), nums.begin(), nums.end());

    return ans;
};

vector<int> quests::array1::shuffle(vector<int> &nums, int n) {
    vector<int> ans(2 * n);

    for (int i : views::iota(0, n)) {
        ans[2 * i] = nums[i];
        ans[2 * i + 1] = nums[i + n];
    }

    return ans;
}

int quests::array1::findMaxConsecutivesOnes(vector<int> &nums) {
    int great_streak = 0, curr_streak = 0;

    for (auto &n : nums) {
        if (n == 1)
            curr_streak++;
        else
            curr_streak = 0;

        great_streak = max(great_streak, curr_streak);
    }

    return great_streak;
}

static int generatorInt() {
    static int i = 1;
    return i++;
}

vector<int> quests::array1::findErrorNums(vector<int> &nums) {
    vector<int> nums_set(size(nums) + 1, 1);
    nums_set[0] = 0;

    for (auto &n : nums)
        nums_set[n]--;

    vector<int> ans(2);

    for (auto i : views::iota(0u, size(nums)))
        if (nums_set[i] == -1)
            ans[0] = nums[i];
        else if (nums_set[i] == 1)
            ans[1] = i + 1;

    return ans;
};
