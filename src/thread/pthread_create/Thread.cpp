//
// Created by zhuanxu on 17/3/14.
//

#include "Thread.h"

Thread::Thread(const Thread::ThreadFunc &func)
        : func_(func),
          autoDelete_(false) {}

void Thread::Start() {
    pthread_create(&threadId_, nullptr,ThreadRoute,this);
}

void Thread::Join() {
    pthread_join(threadId_, nullptr);
}

void Thread::Run() {
    func_();
}

void *Thread::ThreadRoute(void * arg) {
    Thread* thread = static_cast<Thread*>(arg);
    thread->Run();
    if (thread->autoDelete_){
        delete thread;
    }
    return nullptr;
}


