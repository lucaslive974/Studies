#include "leetcode.hpp"
#include <functional>
#include <stack>
#include <unordered_map>

unordered_map<string, function<int(int, int)>> operations{
    {"+", plus<int>()}, {"-", minus<int>()}, {"/", divides<int>()}, {"*", multiplies<int>()}};

int quests::stack1::evalRPN(vector<string> &tokens) {
    stack<int> evaluation;

    for (auto &token : tokens) {
        if (token != "+" && token != "-" && token != "/" && token != "*") {
            evaluation.push(stoi(token));
            continue;
        }

        auto op = operations[token];

        int right = evaluation.top();
        evaluation.pop();

        int left = evaluation.top();
        evaluation.pop();

        int res = op(left, right);
        evaluation.push(res);
    }

    return evaluation.top();
};

vector<int> quests::stack1::exclusiveTime(int n, vector<string> &logs) {
    vector<int> ans(n, 0);

    stack<int> callstack;
    int last_timestamp = 0;

    for (auto &log : logs) {
        auto parts =
            log | views::split(':') | views::transform([](auto &&rng) { return string_view{rng.begin(), rng.end()}; });

        auto it = parts.begin();
        int id = stoi(string(*it++));
        string_view op = *it++;
        int timestamp = stoi(string(*it));

        if (!empty(callstack))
            ans[callstack.top()] += timestamp - last_timestamp;

        if (op == "start")
            callstack.push(id);
        else {
            ans[callstack.top()]++;
            callstack.pop();
            timestamp++;
        }

        last_timestamp = timestamp;
    }

    return ans;
};
