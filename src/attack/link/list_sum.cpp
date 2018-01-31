//
// Created by zhuanxu on 2018/1/26.
//


#include <iostream>
#include "snode.h"


SNode* Add(SNode* pHead1, SNode* pHead2){
    auto pSum = new SNode(0);
    SNode* p1 = pHead1->pNext;
    SNode* p2 = pHead2->pNext;
    // pHead->p1->p2->p3
    // pHead->p1->p2->p3
    // pSum->...->pTail
    auto pTail = pSum;
    int carry = 0;
    while (p1 && p2){
        int value = p1->value + p2->value + carry;
        carry = value / 10;
        value = value % 10;
        auto node = new SNode(value);
        pTail->pNext = node;
        pTail = node;
        p1 = p1->pNext;
        p2 = p2->pNext;
    }
    auto p = p1 ? p1 : p2;
    while (p) {
        int value = p->value + carry;
        carry = value / 10;
        value = value % 10;
        auto node = new SNode(value);
        pTail->pNext = node;
        pTail = node;
        p = p->pNext;
    }
    return pSum;
}


int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 9);

    auto pHead1 = new SNode(0);

    for (int i = 0; i < 6; ++i) {
        auto  p = new SNode(dis(gen));
        p->pNext = pHead1->pNext;
        pHead1->pNext = p;
    }

    auto pHead2 = new SNode(0);
    for (int i=0;i<10;i++){
        auto  p = new SNode(dis(gen));
        p->pNext = pHead2->pNext;
        pHead2->pNext = p;
    }

    Print(pHead1);
    Print(pHead2);

    SNode* pSum = Add(pHead1, pHead2);
    Print(pSum);

    Destroy(pHead1);
    Destroy(pHead2);
    Destroy(pSum);
}