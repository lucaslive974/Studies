#include "patterns.hpp"

int main(int argc, char **argv) { // NOLINT(modernize-use-trailing-return-type): Main function
    crtp();
    mixin();
    sfinae();
    concepts();
    pimpl();
    typeTraits();
    memory();

    return 0;
}
