#include "patterns.hpp"
#include "utils.hpp"
#include <vector>

int main(int argc, char **argv) { // NOLINT(modernize-use-trailing-return-type): Main function
    std::cout << std::format("[{}]", "CPP Idioms") << "\n\n";

    std::vector<std::pair<std::string, utils::PatternFunction>> patterns = {
#define IDIOMS_LIST
#include "idioms.cpp.inc"
    };

    for (const auto &pattern : patterns) {
        utils::executePattern(pattern.first, pattern.second);
    }

    return 0;
}