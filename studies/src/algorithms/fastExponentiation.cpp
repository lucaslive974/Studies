#include "algorithms.hpp"

int algorithms::numeric::fastExponentiation(int num, int expo) {
    if (expo == 0)
        return 1;

    int half = fastExponentiation(num, expo / 2);
    half *= half;

    if (expo & 1)
        half *= num;

    return half;
};
