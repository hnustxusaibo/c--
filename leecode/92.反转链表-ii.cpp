/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head == nullptr) return head;
        ListNode root(0, head);
        ListNode* prev = &root;
        for (int i = 0; i < left - 1; i++) prev = prev->next;
        ListNode* current = prev->next;
        ListNode* next;
        for (int i = left; i < right; i++) {
            next = current->next;
            current->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return root.next;
    }
};
// @lc code=end
