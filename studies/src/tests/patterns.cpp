#include "patterns.hpp"
#include "utils.hpp"
#include <vector>

int main(int argc, char **argv) { // NOLINT(modernize-use-trailing-return-type): Main function
    std::cout << std::format("[{}]", "Design Patterns") << "\n\n";

    std::vector<std::pair<std::string, utils::PatternFunction>> patterns = {
        {"CRTP", crtp},      {"Mixin", mixin},
        {"SFINAE", sfinae},  {"Concepts", concepts},
        {"Pimpl", pimpl},    {"Type Traits", typeTraits},
        {"Memory", memory},  {"Type Erasure", typeErasure},
        {"Lifting", lifting}};

    for (const auto &pattern : patterns) {
        utils::executePattern(pattern.first, pattern.second);
    }

    return 0;
}