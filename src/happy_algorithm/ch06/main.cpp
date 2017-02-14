//
// Created by zhuanxu on 17/2/14.
//
#include <deque>
#include <iostream>
//#include <functional>
#include "state.h"

using namespace std;
int BOAT_ACTIONS[2][5][5] = {
        // 船过去
        {
                {-1, 0, 1,  0, 1},
                {-2, 0, 2,  0, 1},
                {0, -1, 0, 1,  1},
                {0, -2, 0, 2,  1},
                {-1, -1, 1,  1,  1},
        },
        {
                // 船回来
                {1,  0, -1, 0, -1},
                {2,  0, -2, 0, -1},
                {0, 1,  0, -1, -1},
                {0, 2,  0, -2, -1},
                {1,  1,  -1, -1, -1},
        }
};


void searchStates(deque<State> &states);

bool isProcessedState(deque<State, allocator<State>> &states, State state);

void printResults(deque<State, allocator<State>> &states);

void searchActionOnState(deque<State> &states, State current, int *action) {
    //
//    for (int i = 0; i < 5; i++) {
//        cout << action[i] << " ";
//    }
//    cout << endl;

    State next = current.takeAction(action);
//    next.printState();
//    cout << next.isLegalState() << endl;
    if (next.isLegalState() && ! isProcessedState(states, next))
    {
        states.push_back(next);
        searchStates(states);
        states.pop_back();
    }
}

bool isSameState(State state1, State state2) {
    return state1.isSameState(state2);
}

bool isProcessedState(deque<State> &states, State state) {
    auto it = find_if(states.begin(), states.end(), bind2nd(ptr_fun(isSameState), state));
    return it != states.end();
}


void searchStates(deque<State> &states) {
    State current = states.back();
//    current.printState();
    if (current.isFinalState()) {
        printResults(states);
        return;
    }

    int pos = current.getPos();
    int (*boatActions)[5] = BOAT_ACTIONS[pos];
    for (int i = 0; i < 5; i++) {
        int *possibleAction = boatActions[i];
        searchActionOnState(states, current, possibleAction);
    }
}

void printResults(deque<State, allocator<State>> &states) {
    cout << "find result " << endl;
    for_each(states.begin(), states.end(), mem_fun_ref(&State::printState));
    cout << endl << endl;
}


int main() {
    deque<State> states;
    states.push_back(State());
    searchStates(states);
}

