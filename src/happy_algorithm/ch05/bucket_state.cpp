#include <iostream>
#include "bucket_state.h"

int buckets_capcity[] = {8,5,3};
int buckets_init_state[] = {8,0,0};
int buckets_final_state[] = {4,4,0};

BucketState::BucketState() {
    setBuckets(buckets_init_state);
    setAction(8,-1,0);
}

BucketState::BucketState(const int *buckets) {
    setBuckets(buckets);
    setAction(8,-1,0);
}

void BucketState::setBuckets(const int *buckets) {
    for (int i=0;i<BUCKETS_COUNT;i++){
        bucket_s[i] = buckets[i];
    }
}

void BucketState::setAction(int water, int from, int to) {
    curAction.from = from;
    curAction.to   = to;
    curAction.water = water;
}

bool BucketState::isFinalState() {
    return isSameState(BucketState(buckets_final_state));
}

bool BucketState::isSameState(const BucketState &other) const {
    for(int i=0;i<BUCKETS_COUNT;i++){
        if (bucket_s[i] != other.bucket_s[i]){
            return false;
        }
    }
    return true;
}

void BucketState::printStates() {
    std::cout << "Dump " << curAction.water << " water from "
              << curAction.from + 1 << " to " << curAction.to + 1 << ", ";
    std::cout << "buckets water states is : ";

    for(int i = 0; i < BUCKETS_COUNT; ++i)
    {
        std::cout << bucket_s[i] << " ";
    }
    std::cout << std::endl;
}

bool BucketState::canTakeDumpAction(int from, int to) {
    return !(from == to || isEmptyBucket(from) || isFullBucket(to));
}

bool BucketState::isEmptyBucket(int from) {
    return bucket_s[from] == 0;
}

bool BucketState::isFullBucket(int to) {
    return bucket_s[to] == buckets_capcity[to];
}

bool BucketState::dumpWater(int from, int to, BucketState &next) {
    // 在调用这个函数之前，先判断 canTakeDumpAction
    int dumper = buckets_capcity[to] - bucket_s[to];
    next.setBuckets(bucket_s);
    if (bucket_s[from] < dumper){ // 不到dumper
        dumper = bucket_s[from];
    }
    // 倒出 dumper
    next.bucket_s[from] -= dumper;
    next.bucket_s[to] += dumper;

    if (dumper>0){
        next.setAction(dumper,from,to);
        return true;
    }
    return false;
}


