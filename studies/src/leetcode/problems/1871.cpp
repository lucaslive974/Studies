#include "leetcode.hpp"

bool solution::canReach(string s, int minJump, int maxJump) {
    int n = size(s);

    if (s[n - 1] == '1')
        return false;

    int buffer_size = maxJump + 1;
    vector<bool> reachable(buffer_size, 0);
    reachable[0] = true;

    for (int i = 1, valids = 0; i < n; i++) {
        reachable[i % buffer_size] = false;

        if (i >= minJump && reachable[(i - minJump) % buffer_size])
            valids++;

        if (i > maxJump && reachable[(i - maxJump - 1) % buffer_size]) {
            valids--;
        }

        if (s[i] == '0' && valids > 0)
            reachable[i % buffer_size] = true;
    }

    return reachable[(n - 1) % buffer_size];
};
