//
// Created by zhuanxu on 2018/7/7.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
//    Input: 1->2->3->4->5->NULL

//           head
//    Output: 5->4->3->2->1->NULL
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = nullptr;
        while(head) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};