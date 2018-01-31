//
// Created by zhuanxu on 2018/1/27.
//

#ifndef HAPPY_CODE_SNODE_H
#define HAPPY_CODE_SNODE_H

#include <random>
#include <iostream>

typedef struct tagSNode {
    int value;
    tagSNode* pNext;

    explicit tagSNode(int v):value(v),pNext(nullptr){}
}SNode;

void Print(SNode *pHead){
    SNode* p = pHead->pNext;
    while (p){
        std::cout << p->value;
        if (p->pNext){
            std::cout << " -> ";
        }
        p = p->pNext;
    }
    std::cout << std::endl;
}

void Destroy(SNode *p){
    SNode* pNext;
    while (p->pNext){
        pNext = p->pNext;
        delete p;
        p = pNext;
    }
}

int Length(SNode *pHead){
    int length = 0;
    auto p = pHead->pNext;
    while (p){
        length ++;
        p = p->pNext;
    }
    return length;
}

SNode* Tail(SNode* p){
    while (p->pNext){
        p = p->pNext;
    }
    return p;
}


SNode* Init(int length, int begin = 1, int end=9) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(begin, end);

    auto pHead = new SNode(0);

    for (int i = 0; i < length; ++i) {
        auto  p = new SNode(dis(gen));
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    return pHead;
}

#endif //HAPPY_CODE_SNODE_H
