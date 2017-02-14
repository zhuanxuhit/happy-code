//
// Created by zhuanxu on 17/2/14.
//

#ifndef HAPPY_CODE_STATE_H
#define HAPPY_CODE_STATE_H

// 总共有下面10种动作
// 0 和 1 区分船的位置

class State {
public:

    State();

    State(int pInt[5]);


    int getPos() { return state_s[4]; }

    State takeAction(int *action);

    bool isSameState(State state);

    bool isFinalState();

    void printState();

    bool isLegalState();


private:
    int state_s[5];
    int action_s[5];
//    int local_monster;
//    int local_monk;
//    int remote_monster;
//    int remote_monk;
//    int pos;

    void setState(int states[5]);

    void setActions(int pInt[5]);

    void doAction(int *actions);

};


#endif //HAPPY_CODE_STATE_H
