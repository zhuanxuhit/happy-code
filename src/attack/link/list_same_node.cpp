//
// Created by zhuanxu on 2018/1/27.
//

#include "snode.h"
#include <cassert>

SNode* FindFirstSameNode(SNode* pHead1, SNode* pHead2){
    int lenght1 = Length(pHead1);
    int lenght2 = Length(pHead2);
    // 假设 pHead1 < pHead2
    if(lenght1 > lenght2){
        std::swap(lenght1, lenght2);
        std::swap(pHead1, pHead2);
    }
    // a:         a1->a2->a3->a4 = 4
    // b: b1->b2->b3->b4->b5->b6 = 6
    auto p1 = pHead1->pNext;
    auto p2 = pHead2->pNext;
    for(int i=0;i<lenght2-lenght1;i++){
        p2 = p2->pNext;
    }
    while (p1 && p2){
        if (p1 == p2){
            return  p1;
        }
        p1 = p1->pNext;
        p2 = p2->pNext;
    }
    return nullptr;
}

int main() {
    auto pSame = Init(5);
    auto pHead1 = Init(1);
    auto pHead2 = Init(5);
    auto tail1 = Tail(pHead1);
    auto tail2 = Tail(pHead2);
    tail1->pNext = pSame->pNext;
    tail2->pNext = pSame->pNext;
    Print(pHead1);
    Print(pHead2);
    auto same = FindFirstSameNode(pHead1,pHead2);
    assert(same == pSame->pNext);
//    Print(same);
}