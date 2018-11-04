//
// Created by zhuanxu on 2018/7/7.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
//    1 ≤ m ≤ n ≤ length of list.
//    Input: 1->2->3->4->5->NULL, m = 2, n = 4
//    Output: 1->4->3->2->5->NULL
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        //  2-3->4 逆转 4->3->2 所以我们需要知道 preHead 以及 tail
        ListNode *newhead = nullptr;
        ListNode *newtail = nullptr;
        ListNode *preHead = nullptr;
        ListNode *cur = head;
        int index = 1;
        for (; index < m; index++) {
            preHead = cur;
            cur = cur->next;
        }
        newtail = cur;
        for (; index<=n;index++) {
            ListNode *next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        newtail->next = cur;
        if (preHead) {
            preHead->next = newhead;
            return head;
        }else {
            return newhead;
        }

    }
};