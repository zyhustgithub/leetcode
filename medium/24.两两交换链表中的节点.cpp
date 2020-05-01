/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *pre = head;
        ListNode *post = head->next;
        ListNode *tmp = NULL;
        head = post;
        if (head == NULL) {
            return pre;
        }
        while (post != NULL) {
            tmp = post->next;
            post->next = pre;
            if (tmp != NULL) {
                if (tmp->next != NULL) {
                    pre->next = tmp->next;
                    pre = tmp;
                    post = tmp->next;
                } else {
                    pre->next = tmp;
                    break;
                }
            } else {
                pre->next = tmp;
                break;
            }
        }
        return head;
    }
};
// @lc code=end

