//
// Created by zhuanxu on 2018/7/7.
//


struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        int index = 0;
        std::vector < RandomListNode * > copy;
        std::map < RandomListNode * , int > map;
        copy.clear();
        RandomListNode *ptr = head;
        while (ptr) {
            map[ptr] = index++;
            copy.push_back(new RandomListNode(ptr->label));
            ptr = ptr->next;
        }
        copy.push_back(nullptr);
        ptr = head;
        index = 0;
        while (ptr){
            copy[index]->next  =  copy[index+1];
            if (ptr->random){
                copy[index]->random = copy[map[ptr->random]];
            }
            ptr = ptr->next;
            index++;
        }
        return copy[0];
    }
};