//
// Created by zhuanxu on 17/2/14.
//

#include "state.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//const POS_STATE = 4;

// monster, monk
int state_init[] = {3, 3, 0, 0, 0};
int state_final[] = {0, 0, 3, 3, 1};

int action_init[] = {0,0,0,0,0};

void printInts(int *p) {
    for (int i =0;i<5;i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

State::State(int *states) {
    setState(states);
    setActions(action_init);
}


State::State() {
    setState(state_init);
    setActions(action_init);
}

void State::setState(int *states) {
    for (int i=0;i<5;i++){
        state_s[i] =  states[i];
    }
//    local_monster = states[0];
//    local_monk = states[1];
//    remote_monster = states[2];
//    remote_monk = states[3];
//    pos = states[4];
}

void State::setActions(int *actions) {
    for (int i=0;i<5;i++){
        action_s[i] =  actions[i];
    }
}

State State::takeAction(int *action) {
    State state(*this);
    state.doAction(action);
    state.setActions(action);
    return state;
}

void State::doAction(int *actions) {
    for (int i=0;i<5;i++) {
        state_s[i] += actions[i];
    }
}

bool State::isLegalState() {
//    for_each(&state_s[0],&state_s[5],lamda)
//    printInts(state_s);
    // 2 3 1 0 1
    // 数量对
    for (int i=0;i<4;i++) {
        if (state_s[i] < 0  || state_s[i] > 3){
            return false;
        }
    }
    if ((state_s[0] > state_s[1] && state_s[1]!=0)|| (state_s[2] > state_s[3] && state_s[3] !=0)) {
        // monster > monk
        return false;
    }
    // pos ok
    return !(state_s[4] != 0 && state_s[4] != 1);
}

bool State::isSameState(State state) {
    for(int i=0;i<5;i++){
        if (state_s[i] != state.state_s[i]) {
            return false;
        }
    }
    return true;
}

bool State::isFinalState() {
    return isSameState(State(state_final));
}

void State::printState() {
    ostringstream state;

    string action = "";
    action = action_s[4] == 1 ? "过河" : "回来";
    int monster = 0;
    int monk = 1;
    if (action_s[4] == 1){
        monster = 2;
        monk = 3;
    }
    if (action_s[monster] != 0){
        state << action_s[monster] << "个怪物";
//            "?个怪物"
    }
    if (action_s[monk] != 0){
//            "?个和尚"
        state << action_s[monk] << "个和尚";
    }
    if ("" != state.str()){
        state << action;
        cout << state.str() << endl;
    }
}






