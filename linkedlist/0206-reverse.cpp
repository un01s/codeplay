/*
 * leetcode 206
 * reverse
 *
 */

// double-pointer
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = nullptr;
        ListNode* pre = head;
        while(pre != nullptr) {
            ListNode* t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return cur;
    }
};




