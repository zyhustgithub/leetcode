/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0;
        int len2 = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 != nullptr) {
            ++len1;
            p1 = p1->next;
        }
        while (p2 != nullptr) {
            ++len2;
            p2 = p2->next;
        }
        int overflow = 0;
        ListNode *outList = new ListNode(-1);
        ListNode *tmpPtr = outList;
        while ((l1 != nullptr) || (l2 != nullptr)) {
            int sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += overflow;
            tmpPtr->next = new ListNode(sum % 10);
            tmpPtr = tmpPtr->next;
            overflow = sum / 10;
        }
        if (overflow) {
            tmpPtr->next = new ListNode(overflow);
        }
        tmpPtr = outList->next;
        delete outList;
        return tmpPtr;
    }
};
// @lc code=end

