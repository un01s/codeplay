/*
 * leetcode 21
 * merge two sorted lists, maintain the order
 * return the head node of the merged linked list
 *
 */

//
// iterative + dummy node
//
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = list1;
        ListNode* q = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* d = dummy;
        while (p != nullptr && q != nullptr) {
            if (p->val <= q->val) {
                d->next = p;
                p = p->next;
            } else {
                d->next = q;
                q = q->next;
            }
            d = d->next;
        }
        if (p != nullptr) {
            d->next = p;
        }
        if (q != nullptr) {
            d->next = q;
        }
        return dummy->next;
    }
};

// 
// recursive
//
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = list1;
        ListNode* q = list2;

        if (p == nullptr) {
            return q;
        }
        if (q == nullptr) {
            return p;
        }
        if (p->val <= q->val) {
            p->next = mergeTwoLists(p->next, q);
            return p;
        }
        q->next = mergeTwoLists(p, q->next);
        return q;
    }
};

