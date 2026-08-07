#include "leetcode.hpp"

#include <algorithm>
#include <ranges>
#include <stack>

vector<int> quests::monotonic1::finalPrices(vector<int> &prices) {
    int n = size(prices);
    vector<int> ans(n);
    stack<int> monotonic_inc_stack;

    monotonic_inc_stack.push(0);
    ans[0] = prices.front();

    for (auto [idx, price] : prices | views::enumerate | views::drop(1)) {
        while (!empty(monotonic_inc_stack) && price <= prices[monotonic_inc_stack.top()]) {
            int prev = monotonic_inc_stack.top();
            monotonic_inc_stack.pop();
            ans[prev] = prices[prev] - price;
        }

        monotonic_inc_stack.push(idx);
        ans[idx] = price;
    }

    return ans;
}

vector<int> quests::monotonic1::dailyTemperatures(vector<int> &temperatures) {
    stack<int> monotonic_dec_stack;
    vector<int> ans(size(temperatures), 0);

    monotonic_dec_stack.push(0);
    for (auto [i, temperature] : temperatures | views::enumerate | views::drop(1)) {
        while (!empty(monotonic_dec_stack) && temperature > temperatures[monotonic_dec_stack.top()]) {
            int idx = monotonic_dec_stack.top();
            monotonic_dec_stack.pop();
            ans[idx] = i - idx;
        }

        monotonic_dec_stack.push(i);
    }

    return ans;
};

int quests::monotonic1::largestRectangleArea(vector<int> &heights) {
    int n = size(heights);
    vector<int> shorter_right(n, 0), shorter_left(n, 0);
    stack<int> monotonic_inc_stack;

    auto evaluate_monotonic_prop = [&heights, &monotonic_inc_stack](vector<int> &output, int i) {
        while (!empty(monotonic_inc_stack) && heights[i] < heights[monotonic_inc_stack.top()]) {
            int last_height = monotonic_inc_stack.top();
            monotonic_inc_stack.pop();
            output[last_height] = i;
        }
        monotonic_inc_stack.push(i);
    };

    auto empty_monotonic_stack = [&heights, &monotonic_inc_stack](vector<int> &output, int i) {
        while (!empty(monotonic_inc_stack)) {
            int last_height = monotonic_inc_stack.top();
            monotonic_inc_stack.pop();
            output[last_height] = i;
        }
    };

    // First element initialization
    monotonic_inc_stack.push(0);
    for (auto [i, height] : heights | views::enumerate | views::drop(1))
        evaluate_monotonic_prop(shorter_right, i);
    empty_monotonic_stack(shorter_right, n);

    monotonic_inc_stack.push(n - 1);
    for (auto [i, height] : heights | views::enumerate | views::reverse | views::drop(1))
        evaluate_monotonic_prop(shorter_left, i);
    empty_monotonic_stack(shorter_left, -1);

    vector<int> areas(n);
    for (auto [i, pair] : views::zip(shorter_left, shorter_right) | views::enumerate) {
        auto [left_shorter, right_shorter] = pair;
        int width = right_shorter - left_shorter - 1;

        areas[i] = heights[i] * width;
    }

    return *ranges::max_element(areas);
};
