#include <concepts>
#include <ranges>
#include <vector>

namespace algorithms {

using namespace std;
namespace sorting {
template <typename T>
concept Comparable = requires(T &a, T &b) {
    { a < b } -> std::same_as<bool>;
    { a > b } -> std::same_as<bool>;
    { a == b } -> std::same_as<bool>;
};

template <typename T, typename Concrete> struct CmpOp {
    bool operator()(T &a, T &b) { return static_cast<Concrete const *>(this)->cmp(a, b); };
};

template <Comparable T> struct Greater : CmpOp<T, Greater<T>> {
    using type = T;
    bool cmp(T &a, T &b) const { return a > b; }
};

template <Comparable T> struct Less : CmpOp<T, Less<T>> {
    bool cmp(T &a, T &b) const { return a < b; }
};

template <typename T, typename Op> int bubbleSort(vector<T> &vec, CmpOp<T, Op> operation) {
    int operations = 0;
    int size = vec.size();

    for (auto idx1 : views::iota(0, size - 1)) {
        for (auto idx2 : views::iota(0, size - 1)) {
            ++operations;
            if (!operation(vec[idx2], vec[idx2 + 1])) {
                swap(vec[idx2 + 1], vec[idx2]);
            }
        }
    }
    return operations;
};

template <typename T, typename Op> int mergeSort(vector<T> &vec, CmpOp<T, Op> operation) {
    if (vec.size() <= 1)
        return 0;

    int operations = 0;
    auto split = [&operation, &operations, &vec](auto self, int start, int end) -> std::vector<int> {
        if (end - start == 1)
            return {vec[start]};

        auto middle = start + ((end - start) / 2);

        auto left = self(self, start, middle);
        auto right = self(self, middle, end);

        auto leftIt = left.begin();
        auto rightIt = right.begin();

        std::vector<int> result;
        while (leftIt != left.end() && rightIt != right.end()) {
            ++operations;
            if (operation(*leftIt, *rightIt)) {
                result.push_back(*leftIt);
                ++leftIt;
            } else {
                result.push_back(*rightIt);
                ++rightIt;
            }
        }

        while (leftIt != left.end()) {
            ++operations;
            result.push_back(*leftIt);
            ++leftIt;
        }

        while (rightIt != right.end()) {
            ++operations;
            result.push_back(*rightIt);
            ++rightIt;
        }

        return result;
    };

    vec = split(split, 0, vec.size());
    return operations;
};

int insertionSort();
int selectionSort();
int quickSort();
} // namespace sorting

namespace lists {
void floyd();
} // namespace lists

namespace graphs {
void dfs();
void bfs();
} // namespace graphs

namespace numeric {
unsigned int fastExponentiation(unsigned int num, unsigned int expo);
unsigned int powerOfTwoExponentiation(unsigned int num, unsigned int expo);
} // namespace numeric

} // namespace algorithms