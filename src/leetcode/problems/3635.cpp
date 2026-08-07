#include "leetcode.hpp"
#include <algorithm>
#include <limits>
#include <ranges>

int solution::earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime,
                                 vector<int> &waterDuration) {

    auto solve = [](vector<int> &start1, vector<int> &duration1, vector<int> &start2, vector<int> &duration2) {
        int finish1 = numeric_limits<int>::max();
        for (auto i : views::iota(0uz, size(start1)))
            finish1 = min(finish1, start1[i] + duration1[i]);

        int finish2 = numeric_limits<int>::max();
        for (auto i : views::iota(0uz, size(start2)))
            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);

        return finish2;
    };

    int landWater = solve(landStartTime, landDuration, waterStartTime, waterDuration);
    int waterLand = solve(waterStartTime, waterDuration, landStartTime, landDuration);

    return min(landWater, waterLand);
}
