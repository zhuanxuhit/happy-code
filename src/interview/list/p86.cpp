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
    ListNode* partition(ListNode* head, int x) {
//        Input: head = 1->4->3->2->5->2, x = 3
//        Output: 1->2->2->4->3->5
        ListNode smallHead = ListNode(0);
        ListNode bigHead = ListNode(0);
        ListNode *smallTail = &smallHead;
        ListNode *bigTail = &bigHead;
        while (head){
            if (head->val < x) {
                smallTail->next = head;
                smallTail = head;
            }else {
                bigTail->next = head;
                bigTail = head;
            }
            head = head->next;
        }
        smallTail->next = bigHead.next;
        bigTail->next = nullptr;
        return smallHead.next;
    }
};