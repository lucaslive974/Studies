#include "leetcode.hpp"
#include <ranges>

vector<int> solution::findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    int n = size(A);
    vector<int> prefix_occurrence_count(n + 1, 0);
    vector<int> ans;

    int max_common = 0;

    for (auto [a, b] : views::zip(A, B)) {
        prefix_occurrence_count[a]++;
        prefix_occurrence_count[b]++;

        if (prefix_occurrence_count[a] == 2)
            max_common++;

        if (prefix_occurrence_count[b] == 2 && b != a)
            max_common++;

        ans.push_back(max_common);
    }

    return ans;
};
