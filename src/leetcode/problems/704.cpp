#include <math.h>
#include <vector>

class solution {
  public:
    static int search(std::vector<int> &nums, int target) {
        if (nums.empty())
            return -1;

        auto b_search = [&nums, &target](auto &&self, int start, int end) -> int {
            if (start > end)
                return -1;

            int middle = start + (end - start) / 2;
            if (nums[middle] == target)
                return middle;

            if (nums[middle] > target)
                return self(self, start, middle - 1);
            else
                return self(self, middle + 1, end);
        };

        return b_search(b_search, 0, nums.size() - 1);
    }
};
