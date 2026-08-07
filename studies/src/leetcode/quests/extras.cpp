#include <ranges>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    int n = size(digits);

    int carry = 1;
    for (auto &digit : digits | views::reverse) {
        digit += carry;
        carry = digit / 10;
        digit %= 10;
    }

    if (carry)
        digits.insert(begin(digits), 1);

    return digits;
};

bool validMountainArray(vector<int> &arr) {
    int n = size(arr);
    if (n < 3)
        return false;

    // find first inflexion
    int inflection = n;
    for (auto [i, pair] : arr | views::adjacent<2> | views::enumerate) {
        const auto &[curr, next] = pair;

        if (curr == next)
            return false;

        if (curr > next) {
            inflection = i;
            break;
        }
    }

    // checks if's monotonic array
    if (inflection == 0 || inflection == n)
        return false;

    for (auto [curr, next] : arr | views::adjacent<2> | views::drop(inflection)) {
        if (curr <= next)
            return false;
    }

    return true;
}
