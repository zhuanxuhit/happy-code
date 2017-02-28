//
// Created by zhuanxu on 17/2/28.
//


#include <cstdlib>
#include <cstdio>


#define MAX_LEVEL 8

typedef struct nodeStructure {
    int key;
    int value;
    struct nodeStructure *forward[1];
} nodeStructure;


typedef struct skiplist {
    int level;
    nodeStructure *header;
} skiplist;


// 创建节点
nodeStructure *createNode(int level, int key, int value) {

    nodeStructure *ns = (nodeStructure *) malloc(sizeof(nodeStructure) + level * sizeof(nodeStructure *));

    ns->key = key;

    ns->value = value;

    return ns;
}

//列表的初始化
skiplist *createSkiplist() {

    skiplist *sl = (skiplist *) malloc(sizeof(skiplist));

    sl->level = 0;

    sl->header = createNode(MAX_LEVEL - 1, 0, 0);

    for (int i = 0; i < MAX_LEVEL; i++) {
        sl->header->forward[i] = NULL;
    }

    return sl;
}

// 插入元素
int randomLevel() {

    int k = 1;
    while (rand() % 2)
        k++;

    k = (k < MAX_LEVEL) ? k : MAX_LEVEL;

    return k;
}

bool insert(skiplist *sl, int key, int value) {
    nodeStructure *update[MAX_LEVEL];

    nodeStructure *p, *q = NULL;

    p = sl->header;

    int k = sl->level;
    //从最高层往下查找需要插入的位置
    //填充update
    // 找到比x小的最大的数y
    for (int i = k - 1; i >= 0; i--) {
        while ((q = p->forward[i]) && (q->key < key)) {
            p = q;
        }
        // 结束条件是 q == null || q->key >= key
        update[i] = p;
    }
    // update记录了每层走的那个节点
    //不能插入相同的key
    if (q && q->key == key) {
        return false;
    }
    // q->key > key
    // 递增顺序，找到最大的小于 key的节点
    // update[i] 保存的是要插入新节点的前驱
    //产生一个随机层数K

    //新建一个待插入节点q
    //一层一层插入
    k = randomLevel();
    //更新跳表的level

    if (k > (sl->level)) {
        for (int i = sl->level; i < k; i++) {
            update[i] = sl->header;
        }
        sl->level = k;
    }
    q = createNode(k, key, value);
    //逐层更新节点的指针，和普通列表插入一样
    for (int i = 0; i < k; i++) {
        q->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = q;
    }

    return true;
}

bool deleteSL(skiplist *sl, int key) {

    nodeStructure *update[MAX_LEVEL];

    nodeStructure *p, *q = NULL;

    p = sl->header;

    //从最高层开始搜
    int k = sl->level;

    for (int i = k - 1; i >= 0; i--) {
        while ((q = p->forward[i]) && (q->key < key)) {
            p = q;
        }
        update[i] = p;
    }
    // update[i] 记录的是每层需要查出节点的前继
    if (q && q->key == key) {

        //逐层删除，和普通列表删除一样
        for (int i = 0; i < sl->level; i++) {

            if (update[i]->forward[i] == q) {
                update[i]->forward[i] = q->forward[i];
            }

        }
        free(q);

        //如果删除的是最大层的节点，那么需要重新维护跳表的

        for (int i = sl->level - 1; i >= 0; i--) {
            if (sl->header->forward[i] == NULL) {
                sl->level--;
            }
        }
        return true;
    } else {
        return false;
    }
}

int search(skiplist *sl, int key) {

    nodeStructure *p, *q = NULL;

    p = sl->header;

    //从最高层开始搜

    int k = sl->level;

    for (int i = k - 1; i >= 0; i--) {

        while ((q = p->forward[i]) && (q->key <= key)) {

            if (q->key == key) {
                return q->value;
            }

            p = q;

        }

    }

    return NULL;
}

void printSL(skiplist *sl) {
    //从最高层开始打印
    nodeStructure *p, *q = NULL;

    //从最高层开始搜
    int k = sl->level;
    for (int i = k - 1; i >= 0; i--) {
        p = sl->header;
        while ((q = p->forward[i])) {
            printf("%d -> ", p->value);
            p = q;
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    skiplist *sl = createSkiplist();
    for (int i = 1; i <= 19; i++) {
        insert(sl, i, i * 2);
    }
    printSL(sl);
    //搜索
    int i = search(sl, 4);
    printf("i=%d\n", i);
    //删除
    bool b = deleteSL(sl, 4);
    if (b)
        printf("删除成功\n");
    printSL(sl);
    system("pause");
    return 0;
}