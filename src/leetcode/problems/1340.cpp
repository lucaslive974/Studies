#include "leetcode.hpp"
#include <algorithm>
#include <ranges>

int solution::maxJumps(vector<int> &arr, int d) {
    int n = size(arr);
    vector<int> dp(n, 0);

    auto dfs = [&arr, &dp, d, n](this auto &&self, int idx) -> int {
        // already calculated, return;
        if (dp[idx])
            return dp[idx];

        int left = 1, right = 1;

        int left_jumps = 0;
        // looking for best candidates left, while distance allows
        while (left <= d && left <= idx) {
            int previous = idx - left;

            // found a barrier, cant jump further
            if (arr[idx] <= arr[previous])
                break;

            // Which is the best candidate
            left_jumps = max(self(previous), left_jumps);
            left++;
        }

        int right_jumps = 0;
        // looking for best candidates right, while distance allows
        while (right <= d && idx + right < n) {
            int next = idx + right;

            // found a barrier, cant jump further
            if (arr[idx] <= arr[next])
                break;
            //
            // Which is the best candidate
            right_jumps = max(self(next), right_jumps);
            right++;
        }

        // Jumps on the best side plus itself
        dp[idx] = max(left_jumps, right_jumps) + 1;
        return dp[idx];
    };

    vector<int> ans(n);
    for (int i : views::iota(0, n))
        ans[i] = dfs(i);

    return *ranges::max_element(ans);
}
