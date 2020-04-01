/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }
        if ((head->next == NULL) && (n == 1)) {
            //free(head);
            return NULL;
        }
        ListNode *pre = head;
        ListNode *post = head;
        int num = n;
        while (num-- && post) {
            post = post->next;
        }
        if (num > 0) {
            return NULL;
        }
        if (post == NULL) {
            head = head->next;
            //free(pre);
            return head;
        }
        post = post->next;
        while (post) {
            pre = pre->next;
            post = post->next;
        }
        post = pre->next;
        if(pre->next->next != NULL) {
            pre->next = pre->next->next;
        } else {
            pre->next = NULL;
        }
        //free(post);
        return head;
    }
};
// @lc code=end

