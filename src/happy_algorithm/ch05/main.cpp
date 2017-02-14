#include "bucket_state.h"

#include <deque>
#include <functional>
#include <iostream>


int success = 0;

bool isSameState(BucketState state1, BucketState state2) {
    return state1.isSameState(state2);
}

bool isProcessedState(std::deque<BucketState> &states, BucketState &current) {
    auto it = std::find_if(states.begin(), states.end(), std::bind2nd(std::ptr_fun(isSameState), current));
    return  it != states.end();
}

void printResult(std::deque<BucketState> &states) {
    success++;
    std::cout << "Find " <<  success + 1 << " Result : " << std::endl;
    std::for_each(states.begin(), states.end(),
                  std::mem_fun_ref(&BucketState::printStates));
    std::cout << std::endl << std::endl;
}
void searchStates(std::deque<BucketState> &states);
void searchStateOnAction(std::deque<BucketState> &states, BucketState &current, int from, int to) {
//    std::cout << "try dumper water from " << from + 1 << " to " << to + 1 << std::endl;
    if (current.canTakeDumpAction(from, to)) {
        BucketState next;
        bool bDump = current.dumpWater(from, to, next);
        if (bDump && !isProcessedState(states, next)) {
            states.push_back(next);
            searchStates(states);
            states.pop_back();
        }
    }
}


void searchStates(std::deque<BucketState> &states) {
    BucketState current = states.back();
//    current.printStates();
    if (current.isFinalState()) {
        printResult(states);
        return;
    }
    for (int i = 0; i < BUCKETS_COUNT; i++) {
        for (int j = 0; j < BUCKETS_COUNT; j++) {
            searchStateOnAction(states, current, i, j);
        }
    }
}


int main() {
    std::deque<BucketState> states;
    // 初始化状态
    states.push_back(BucketState());
    searchStates(states);
}