#include "leetcode.hpp"

#include <limits>

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode head;
    ListNode *tail = &head;

    while (list1 || list2) {
        int num_1 = list1 ? list1->val : std::numeric_limits<int>::max();
        int num_2 = list2 ? list2->val : std::numeric_limits<int>::max();

        if (num_1 < num_2) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    return head.next;
}
