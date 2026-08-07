#include "leetcode.hpp"
#include <algorithm>
#include <cctype>
#include <cstring>
#include <numeric>
#include <queue>
#include <ranges>
#include <string>
#include <unordered_set>

using namespace std;

auto remainingMethods(int n, int k, vector<vector<int>> invocations) -> vector<int> {
    vector<vector<int>> adj(n);
    for (const auto &inv : invocations) {
        const auto &caller = inv[0];
        const auto &callee = inv[1];

        adj[caller].push_back(callee);
    }

    vector<bool> tainted(n, false);
    queue<int> frontier;

    frontier.push(k);
    tainted[k] = true;

    while (!empty(frontier)) {
        int current = frontier.front();
        frontier.pop();

        for (int nextMethod : adj[current]) {
            if (!tainted[nextMethod]) {
                tainted[nextMethod] = true;
                frontier.push(nextMethod);
            }
        }
    }

    bool canRemove = true;
    for (const auto &inv : invocations) {
        int caller = inv[0];
        int callee = inv[1];

        if (!tainted[caller] && tainted[callee]) {
            canRemove = false;
            break;
        }
    }

    vector<int> result(n);
    if (!canRemove) {
        return vector<int>(n);
    }

    return result;
}

auto mergeAlternately(string word1, string word2) -> string {
    auto it1 = word1.begin();
    auto it2 = word2.begin();
    auto end1 = word1.end();
    auto end2 = word2.end();

    string merged;
    while (it1 != end1 && it2 != end2) {
        merged += (*it1)++;
        merged += (*it2)++;
        (it1++, it2++);
    }

    if (it1 != end1) {
        merged.append(it1, end1);
    }

    if (it2 != end2) {
        merged.append(it2, end2);
    }

    return merged;
}

auto gcdOfStrings(const string &str1, const string &str2) -> string {
    if (str1 + str2 != str2 + str1) {
        return "";
    }

    int gcdLenght = gcd(size(str1), size(str2));

    return str1.substr(0, gcdLenght);
};

auto kidsWithCandies(vector<int> &candies, int extraCandies) -> vector<bool> {
    int maxCandies = *ranges::max_element(candies);

    vector<bool> result;
    result.reserve(candies.size());
    for (auto &candie : candies) {
        result.push_back((candie + extraCandies) > maxCandies);
    }

    return result;
}

auto canPlaceFlowers(vector<int> &flowerbed, int n) -> bool {
    if (n <= 0) {
        return true;
    }

    for (auto idx : views::iota(0UZ, size(flowerbed))) {
        auto &flower = flowerbed[idx];
        if (flower == 0) {
            int left = (idx == 0) ? 0 : flowerbed[idx - 1];
            int right = (idx == size(flowerbed) - 1) ? 0 : flowerbed[idx + 1];

            if ((left == 0) && (right == 0)) {
                flower = 1;
                n--;
            }

            if (n == 0) {
                return true;
            }
        }
    }

    return n <= 0;
}

auto reverseVowerls(string s) -> string {
    unordered_set<char> vowels = []() -> unordered_set<char> { return unordered_set<char>{'a', 'e', 'i', 'o', 'u'}; }();
    auto isVowel = [&](char c) -> bool {
        auto cl = tolower(c);
        return vowels.contains(cl);
    };

    string result;
    auto lastVowel = s.end();
    for (auto character : s) {
        if (!isVowel(character)) {
            result += character;
            continue;
        }
    }

    return result;
};

auto reverseWords(string s) -> string {
    string result;
    auto it = s.rbegin();

    while (it != s.rend()) {
        while (it != s.rend() && isspace(*it)) {
            ++it;
        }

        if (it == s.rend())
            break;

        auto wordEnd = it;

        while (it != s.rend() && !isspace(*it)) {
            ++it;
        }

        if (!result.empty()) {
            result += ' ';
        }

        result.append(it.base(), wordEnd.base());
    }

    return result;
}

auto productExceptSelf(vector<int> &nums) -> vector<int> {
    size_t nsize = size(nums);
    vector<int> leftProduct{1};
    vector<int> rightProduct{1};

    for (auto num : nums | views::take(nsize - 1)) {
        auto product = leftProduct.back() * num;
        leftProduct.push_back(product);
    }

    for (auto num : views::reverse(nums) | views::take(nsize - 1)) {
        auto product = rightProduct.back() * num;
        rightProduct.push_back(product);
    }

    auto resultView = views::zip_transform([](int left, int right) -> int { return left * right; }, leftProduct, views::reverse(rightProduct));

    return ranges::to<vector<int>>(resultView);
}
