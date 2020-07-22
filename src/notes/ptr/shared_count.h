//
// Created by 汪超 on 2020/7/17.
//

#ifndef HAPPY_CODE_SHARED_COUNT_H
#define HAPPY_CODE_SHARED_COUNT_H


class shared_count {
public:
    shared_count() noexcept : count_(1) {}

    void add_count() noexcept {
        ++count_;
    }

    long reduce_count() noexcept {
        return --count_;
    }

    long get_count() const noexcept {
        return count_;
    }

private:
    long count_;
};


#endif //HAPPY_CODE_SHARED_COUNT_H
