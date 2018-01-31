//
// Created by zhuanxu on 2018/1/27.
//

#include "snode.h"



void RemoveDuplicate(SNode* pHead){
    SNode* pCur = pHead->pNext;
    while (pCur && pCur->pNext){
        if (pCur->value == pCur->pNext->value){
            auto pDup = pCur->pNext;
            pCur->pNext = pDup->pNext;
            delete pDup;
        } else {
            pCur = pCur->pNext;
        }
    }
}

int main() {
    int a[] = {2,3,3,5,7,8,8,8,9,9,10};
    int length = sizeof(a) / sizeof(int);
    auto pHead = new SNode(0);
    auto pTail = pHead;
    for (int i = 0; i < length; ++i) {
        auto node = new SNode(a[i]);
        pTail->pNext= node;
        pTail = node;
    }
    Print(pHead);
    RemoveDuplicate(pHead);
    Print(pHead);
    Destroy(pHead);
}