#ifndef __BUCKET_STATE__
#define __BUCKET_STATE__

const int BUCKETS_COUNT  = 3;

typedef struct tagAction {
    int from;
    int to;
    int water;
}Action;

class BucketState {
public:
    BucketState();
    BucketState(const int*buckets);

    bool isFinalState();
    void printStates();
    bool canTakeDumpAction(int from, int to);
    bool dumpWater(int from,int to,BucketState &next);
    bool isSameState(const BucketState &other) const ;
private:
    void setBuckets(const int*buckets);
    void setAction(int water,int from,int to);
    Action curAction;
    int bucket_s[BUCKETS_COUNT];

    bool isEmptyBucket(int from);

    bool isFullBucket(int to);
};

#endif