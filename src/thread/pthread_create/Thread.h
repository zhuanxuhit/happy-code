//
// Created by zhuanxu on 17/3/14.
//

#ifndef HAPPY_CODE_THREAD_H
#define HAPPY_CODE_THREAD_H


#include <pthread.h>
#include <boost/function.hpp>

class Thread {
public:
    typedef boost::function<void ()> ThreadFunc;
    explicit Thread(const ThreadFunc& func);

    void Start();
    void Join();

    void SetAutoDelete(bool autoDelete){autoDelete_=autoDelete;}

private:
    static void *(ThreadRoute)(void *);
    void Run();
    ThreadFunc func_;
    pthread_t threadId_;
    bool autoDelete_;
};


#endif //HAPPY_CODE_THREAD_H
