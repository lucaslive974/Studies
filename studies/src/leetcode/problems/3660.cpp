#include <limits>
#include <vector>

using namespace std;

class solution {

  public:
    vector<int> maxValue(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(nums.size(), -1);

        vector<int> max_prefix_idx(nums.size(), 0), min_suffix_idx(nums.size(), n - 1);
        for (int i = 1; i < n; i++)
            max_prefix_idx[i] = nums[i] > nums[max_prefix_idx[i - 1]] ? i : max_prefix_idx[i - 1];

        for (int i = n - 2; i >= 0; i--)
            min_suffix_idx[i] = nums[i] < nums[min_suffix_idx[i + 1]] ? i : min_suffix_idx[i + 1];

        auto solve = [&ans, &nums, &max_prefix_idx, &min_suffix_idx](auto solve_fn, int start, int end, int inherit_optimal, int blocking_min) {
            if (start >= end)
                return;

            int local_optimal_pivot = max_prefix_idx[end - 1];
            int local_optimal = nums[local_optimal_pivot];

            int evaluated_value = local_optimal > blocking_min ? inherit_optimal : local_optimal,
                new_blocking = min(blocking_min, nums[min_suffix_idx[local_optimal_pivot]]);

            ans[local_optimal_pivot] = evaluated_value;

            return solve_fn(solve_fn, start, max_prefix_idx[end - 1], evaluated_value, new_blocking);
        };

        int optimal = 0, blocking_min = numeric_limits<int>::max();
        solve(solve, 0, n, optimal, blocking_min);

        optimal = ans[0];
        for (int i = 1; i < n; i++) {
            if (ans[i] != -1)
                optimal = ans[i];

            ans[i] = optimal;
        }

        return ans;
    }
};
