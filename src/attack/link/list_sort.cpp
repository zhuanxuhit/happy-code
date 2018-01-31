//
// Created by zhuanxu on 2018/1/27.
//

#include "snode.h"

void Partition(SNode* pHead, int x){
    // 小于x和大于x
    SNode* p = pHead->pNext;
    SNode* pLeftHead = new SNode(0);
    SNode* pRightHead = new SNode(0);
    SNode* leftTail = pLeftHead;
    SNode* rightTail = pRightHead;
    while (p){
        auto pCur = p;
        p = p->pNext;
        pCur->pNext = nullptr;
        if (pCur->value < x){
            leftTail->pNext = pCur;
            leftTail = pCur;
        }
        else {
            rightTail->pNext = pCur;
            rightTail = pCur;
        }
    }
    pHead->pNext = pLeftHead->pNext;
    leftTail->pNext = pRightHead->pNext;
}


int main() {
    SNode* pHead = Init(10,1,100);
    Print(pHead);

    Partition(pHead, 50);
    Print(pHead);
    Destroy(pHead);
}