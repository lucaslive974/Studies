#include "leetcode.hpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

ListNode *solution::addTwoNumber(ListNode *l1, ListNode *l2) {
    int carry = 0;

    ListNode sentinel;
    ListNode *tail = &sentinel;

    while (l1 != nullptr || l2 != nullptr || carry) {
        int res = 0;
        if (l1) {
            res += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            res += l2->val;
            l2 = l2->next;
        }

        res += carry;
        carry = res / 10;

        ListNode *curr = new ListNode(res % 10);
        tail->next = curr;
        tail = curr;
    }

    return sentinel.next;
};
