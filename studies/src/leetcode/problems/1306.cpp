#include "leetcode.hpp"
#include <ios>
#include <iostream>
#include <stack>

bool solution::canReach(vector<int> &arr, int start) {
    stack<int> frontier;
    vector<bool> visited_idx(arr.size(), 0);

    frontier.push(start);
    visited_idx[start] = 1;

    while (!empty(frontier)) {
        int curr = frontier.top();
        frontier.pop();

        if (arr[curr] == 0)
            return true;

        int right = curr + arr[curr], left = curr - arr[curr];
        if (right < size(arr) && !visited_idx[right]) {
            frontier.push(right);
            visited_idx[right] = 1;
        }

        if (left >= 0 && !visited_idx[left]) {
            frontier.push(left);
            visited_idx[left] = 1;
        }
    }

    return false;
};

auto init = []() -> bool {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return true;
}();
