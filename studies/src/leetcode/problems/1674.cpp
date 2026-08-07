#include "leetcode.hpp"

#include <algorithm>
#include <vector>

using namespace std;

int solution::minMoves(vector<int> &nums, int limit) {
    int n = size(nums);
    int n_pairs = n / 2;

    vector<pair<int, int>> pairs;
    for (int i = 0; i < n_pairs; i++) {
        int &a = nums[i], &b = nums[n - 1 - i];
        pairs.push_back({min(a, b) + 1, max(a, b) + limit});
    }

    vector<int> diff_array((limit * 2) + 2, 0);
    for (int i = 0; i < n_pairs; i++) {
        auto &pair = pairs[i];
        auto target = nums[i] + nums[n - 1 - i];

        diff_array[pair.first] -= 1;
        diff_array[pair.second + 1] += 1;

        diff_array[target] -= 1;
        diff_array[target + 1] += 1;
    }

    int answer = n, running = 0;
    for (int target = 2; target <= 2 * limit; target++) {
        running += diff_array[target];

        answer = min(answer, n + running);
    }

    return answer;
}
