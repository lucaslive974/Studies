#include <climits>
#include <vector>

class solution {
  public:
    int maxRotateFunction(std::vector<int> &nums) {
        int output = INT_MIN;

        int rotation = 0;
        while (rotation < nums.size()) {
            int sum = 0, factor = rotation;

            for (auto &n : nums)
                sum += n * (factor++ % nums.size());

            output = std::max(output, sum);
            rotation++;
        }

        return output;
    }

    int maxRotateFunctionOpt(std::vector<int> &nums) {
        int arr_sum = 0, output = 0;

        for (int i = 0; i < nums.size(); i++)
            (arr_sum += nums[i], output += nums[i] * i);

        int k_rotation = output;
        for (int k = nums.size() - 1; k > 0; k--)
            (k_rotation = k_rotation + arr_sum - (nums[k] * nums.size()), output = std::max(output, k_rotation));

        return output;
    }
};
