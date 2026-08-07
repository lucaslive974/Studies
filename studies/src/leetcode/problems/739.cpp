#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

class solution {
  public:
    static std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::stack<int> monotonic_stack;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!monotonic_stack.empty() && temperatures[i] > temperatures[monotonic_stack.top()])
                (res[monotonic_stack.top()] = i - monotonic_stack.top(), monotonic_stack.pop());

            monotonic_stack.push(i);
        }
        return res;
    }
};

auto print_lambda = [](int &n) { std::cout << n << " "; };

int main(int argc, char **argv) {

    std::vector<std::vector<int>> temperatures = {{73, 74, 75, 71, 69, 72, 76, 73}, {30, 40, 50, 60}, {30, 60, 90}};

    std::for_each(temperatures.begin(), temperatures.end(), [](std::vector<int> t) {
        auto res = solution::dailyTemperatures(t);

        std::cout << "[ ";
        std::for_each(res.begin(), res.end(), print_lambda);
        std::cout << " ]" << std::endl;
    });

    return 0;
}
