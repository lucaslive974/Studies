#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

class solution {
    std::unordered_map<char, char> alphabet{{'(', ')'}, {'[', ']'}, {'{', '}'}};

  public:
    inline bool isOpenSymbol(char &c) { return alphabet.find(c) != alphabet.end(); };

    bool isValid(std::string s) {
        std::stack<char> stack;

        for (auto &c : s) {
            if (isOpenSymbol(c)) {
                stack.push(c);
                continue;
            }

            if (stack.empty() || alphabet[stack.top()] != c)
                return false;

            stack.pop();
        }

        return stack.empty();
    }
};

int main(int argc, char **argv) {
    std::string s{"()"};
    solution solution;

    std::cout << solution.isValid(s) << std::endl;

    return 0;
}
