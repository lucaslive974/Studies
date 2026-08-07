#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class solution {
  public:
    bool rotateString(std::string s, std::string goal) {
        if (s.size() != goal.size())
            return false;

        int size = s.size();

        for (int start = 0; start < size; start++) {
            for (int match = 0; match < size; match++) {
                int idx = (match + start) % size;
                if (s[idx] != goal[match])
                    continue;

                if (match == size - 1)
                    return true;
            }
        }

        return false;
    }

    static std::vector<int> buildLps(std::string s) {
        std::vector<int> lps{0};

        int prefix = 0, suffix = 1;
        while (suffix < s.size()) {
            if (s[prefix] == s[suffix]) {
                (lps.push_back(++prefix), suffix++);
                continue;
            }

            if (prefix > 0) {
                prefix = lps[prefix - 1];
                continue;
            }

            (lps.push_back(prefix), suffix++);
        }

        return lps;
    }

    static bool rotateStringOpt(std::string s, std::string goal) {
        if (s.size() != goal.size())
            return false;

        std::vector<int> lps = solution::buildLps(goal);

        int i = 0, j = 0, size = s.size() * 2;
        while (i < size) {
            if (s[i % size] == goal[j])
                (i++, j++);
            else if (j > 0)
                j = lps[j - 1];
            else
                i++;

            if (j == lps.size())
                return true;
        }

        return false;
    }
};

int main(int argc, char **argv) {
    if (argc < 3)
        throw std::invalid_argument("USAGE: string goal");

    std::string s{argv[1]}, goal{argv[2]};

    bool val = solution::rotateStringOpt(s, goal);

    std::cout << val << std::endl;
}
