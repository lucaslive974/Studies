#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class solution {
  public:
    bool isGood(vector<int> &nums) {
        int max = *max_element(nums.begin(), nums.end());

        vector<int> permutations_count(max + 1, 1);
        permutations_count[0] = 0;
        permutations_count[max]++;

        for (auto &num : nums)
            permutations_count[num]--;

        return !count(permutations_count.begin(), permutations_count.end(), 0);
    }
};
