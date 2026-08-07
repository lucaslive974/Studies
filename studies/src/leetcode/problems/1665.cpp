#include "leetcode.hpp"
#include <algorithm>
#include <ios>
#include <iostream>

using namespace std;

struct compares {
    static bool pairs(const std::pair<int, int> &a, const std::pair<int, int> &b) { return a.second > b.second; }
};

int solution::minimumEffort(vector<vector<int>> &tasks) {
    vector<pair<int, int>> cost_benefits(size(tasks));

    for (int i = 0; i < size(tasks); i++)
        cost_benefits[i] = {i, tasks[i][1] - tasks[i][0]};

    sort(cost_benefits.begin(), cost_benefits.end(), compares::pairs);

    vector<vector<int>> sorted_tasks;
    for (auto &pair : cost_benefits)
        sorted_tasks.push_back(tasks[pair.first]);

    int optimal_effort = 0, curr_remaining = 0;
    for (auto &task : sorted_tasks) {
        int &energy_to_start = task[1];
        int &energy_to_finish = task[0];
        if (curr_remaining < energy_to_start) {
            int delta = energy_to_start - curr_remaining;
            curr_remaining += delta - energy_to_finish;
            optimal_effort += delta;
        } else {
            curr_remaining -= energy_to_finish;
        }
    }

    return optimal_effort;
};

auto init = []() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return true;
}();
