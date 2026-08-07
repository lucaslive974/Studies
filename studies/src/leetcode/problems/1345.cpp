#include "leetcode.hpp"
#include <queue>
#include <ranges>
#include <unordered_map>
#include <unordered_set>

int solution::minJumps(vector<int> &arr) {
    unordered_map<long long, vector<int>> jumps_by_integer;

    for (auto [idx, integer] : views::enumerate(arr))
        jumps_by_integer[integer].push_back(idx);

    int n = size(arr);
    queue<int> frontier;
    vector<int> costs(n, -1);

    frontier.push(0);
    costs[0] = 0;

    while (!empty(frontier)) {
        int idx = frontier.front();
        frontier.pop();

        if (idx == n - 1)
            break;

        if (costs[idx + 1] == -1) {
            costs[idx + 1] = costs[idx] + 1;
            frontier.push(idx + 1);
        }

        if (idx > 0 && costs[idx - 1] == -1) {
            costs[idx - 1] = costs[idx] + 1;
            frontier.push(idx - 1);
        }

        auto it = jumps_by_integer.find(arr[idx]);
        if (it == jumps_by_integer.end())
            continue;

        for (auto &jump : it->second)
            if (costs[jump] == -1) {
                costs[jump] = costs[idx] + 1;
                frontier.push(jump);
            }

        jumps_by_integer.erase(it);
    }

    return costs[n - 1];
};
