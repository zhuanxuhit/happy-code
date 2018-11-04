//
// Created by zhuanxu on 2018/7/7.
//


class MyStack {
private:
    std::queue<int> queue_;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        std::queue<int> temp;
        temp.push(x);

    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {

    }

    /** Get the top element. */
    int top() {

    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return queue_.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */