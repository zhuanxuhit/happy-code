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
    ListNode *detectCycle(ListNode *head) {
        ListNode *pfast = head;
        ListNode *pshort = head;
        while (pshort && pfast) {
            pshort = pshort->next;
            pfast = pfast->next;
            if (pfast == nullptr){
                return nullptr;
            }
            pfast = pfast->next;
            if (pfast == pshort){
                break;
            }
        }
        pshort = head;
        while (pfast && pshort && pfast != pshort) {
            pfast = pfast->next;
            pshort = pshort->next;
        }
        return pfast;
    }
};