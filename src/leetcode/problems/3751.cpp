#include "leetcode.hpp"
#include <ranges>

int solution::totalWaviness(int num1, int num2) {
    int waves = 0;

    auto evaluate = [&waves](const tuple<char &, char &, char &> &values) {
        if (get<0>(values) < get<1>(values) && get<1>(values) > get<2>(values))
            waves++;

        else if (get<0>(values) > get<1>(values) && get<1>(values) < get<2>(values))
            waves++;
    };

    for (auto values : views::iota(num1, num2 + 1)) {
        string range = to_string(values);

        for (auto sub_range : range | views::adjacent<3>)
            evaluate(sub_range);
    }

    return waves;
};
