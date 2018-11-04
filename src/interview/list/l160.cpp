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
    int length(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        A:          a1 → a2
//                            ↘
//                            c1 → c2 → c3
//                            ↗
//        B:     b1 → b2 → b3
        int lengthA = length(headA);
        int lengthB = length(headB);
        ListNode *plong = nullptr;
        ListNode *pshort = nullptr;
        if (lengthA < lengthB) {
            pshort = headA;
            plong = headB;
        } else {
            pshort = headB;
            plong = headA;
        }
        int diff = abs(lengthA - lengthB);
        while (diff-- > 0 && plong) {
            plong = plong->next;
        }

        while (plong && pshort) {
            if (plong == pshort){
                break;
            }
            plong = plong->next;
            pshort = pshort->next;
        }
        return  plong;
    }
};