#include "algorithms.hpp"
#include <bit>
#include <cassert>
#include <iostream>

inline bool isPowerOfTwo(unsigned int num) { return (num > 0 && (num & (num - 1)) == 0); }

unsigned int fastExponentiationRecursive(unsigned int num, unsigned int expo) {
    if (expo == 0)
        return 1;

    unsigned int half = fastExponentiationRecursive(num, expo / 2);
    half *= half;

    if (expo & 1)
        half *= num;

    return half;
};

unsigned int algorithms::numeric::fastExponentiation(unsigned int num, unsigned int expo) {
    if (isPowerOfTwo(num)) {
        std::cout << "Power of 2 Bitshift Exponentiation" << '\n';
        return algorithms::numeric::powerOfTwoExponentiation(num, expo);
    }

    std::cout << "Fast exponentiation" << '\n';
    return fastExponentiationRecursive(num, expo);
}

unsigned int algorithms::numeric::powerOfTwoExponentiation(unsigned int num, unsigned int expo) {
    assert(isPowerOfTwo(num) && "Number must be a power of two to be bitshift exponentiated.");
    return 1 << (std::countr_zero(num) * expo);
}
