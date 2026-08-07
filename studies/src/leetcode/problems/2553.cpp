#include <ios>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int num_array[6];

class solution {
  public:
    vector<int> separateDigits(vector<int> &nums) {
        vector<int> ans;

        for (auto &num : nums) {
            int num_digits = floor(log10(num)) + 1;

            int last_idx = num_digits - 1;
            while (num > 0) {
                num_array[last_idx] = num % 10;
                num /= 10;
                last_idx--;
            }

            ans.insert(ans.end(), num_array, num_array + num_digits);
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return true;
}();
