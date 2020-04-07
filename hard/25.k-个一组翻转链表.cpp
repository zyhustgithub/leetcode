/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *p = head;
        while ((count < k) && (p != nullptr)) {
            p = p->next;
            ++count;
        }
        if (count < k) {
            return head;
        }
        ListNode *next = reverseKGroup(p, k);
        p = head->next;
        head->next = next;
        ListNode *tmp;
        for (int i = 1; i < k; ++i) {
            tmp = p->next;
            p->next = head;
            head = p;
            p = tmp;
        }
        return head;
    }
};
// @lc code=end

