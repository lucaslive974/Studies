#include "leetcode.hpp"
#include <unordered_set>

typedef long long pointer;

bool solution::hasCycle(ListNode *head) {
    std::unordered_set<ListNode *> visited;

    while (head) {
        if (
#if __cplusplus > 202000
            visited.contains(head)
#else
            visited.find(head) != visited.end()
#endif
        )
            return true;

        visited.insert(head);
        head = head->next;
    }

    return false;
}
