/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        int listSize = lists.size();
        if (listSize == 1) {
            return lists[0];
        }
        int interval = 1;
        while (interval < listSize) {
            for (int i = 0; i + interval < listSize; i += 2 * interval) {
                lists[i] = merge(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }

    ListNode *merge(ListNode *lNode, ListNode *rNode)
    {
        ListNode p(-1);
        ListNode *tmp = &p;
        while ((lNode != nullptr) && (rNode != nullptr)) {
            if (lNode->val <= rNode->val) {
                tmp->next = lNode;
                lNode = lNode->next;
            } else {
                tmp->next = rNode;
                rNode = rNode->next;
            }
            tmp = tmp->next;
        }
        tmp->next = (lNode != nullptr) ? lNode : rNode;
        return p.next;
    }
};
// @lc code=end

