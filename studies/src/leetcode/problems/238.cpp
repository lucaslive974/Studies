#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums) {
    std::vector<int> dp{1};

    for (auto &num : nums) {
        dp.push_back(dp.back() * num);
    }

    std::vector<int> res;
    for (auto &num : nums) {
        res.push_back(dp.back() / num);
    }

    return res;
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 2, 3, 4};

    auto result = productExceptSelf(nums);

    for (auto &num : result) {
        std::cout << num << std::endl;
    }

    return 0;
}
