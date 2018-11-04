//
// Created by zhuanxu on 2018/7/7.
//



class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//        Input: 1->2->4, 1->3->4
//        Output: 1->1->2->3->4->4
        ListNode temp = ListNode(0);
        ListNode *tail = &temp;
//        ListNode *next = nullptr;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1) {
            tail->next = l1;
        }
        if (l2) {
            tail->next = l2;
        }
        return temp.next;
    }
};