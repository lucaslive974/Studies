#include "leetcode.hpp"
#include <unordered_map>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

using namespace std;

vector<int> solution::twoSum(vector<int> &nums, int target) {
    std::vector<int> res;
    std::unordered_map<int, int> complement_map;

    int idx = 0;
    for (auto &num : nums) {
        int complement = target - num;
        if (auto it = complement_map.find(complement); it != complement_map.end()) {
            res.insert(res.end(), {it->second, idx});
            break;
        }

        complement_map.insert({num, idx++});
    }

    return res;
}
