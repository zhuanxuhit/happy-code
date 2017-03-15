//
// Created by zhuanxu on 17/3/14.
//

#include <pthread.h>
#include <cstdio>
// getpid
#include <sys/types.h>
#include <unistd.h>

void prepare(void){
//    pid_t getpid(void);
    printf("pid=%d prepare...\n",static_cast<int>(getpid()));
}

void parent(void){
//    pid_t getpid(void);
    printf("pid=%d parent...\n",static_cast<int>(getpid()));
}

void child(void){
//    pid_t getpid(void);
    printf("pid=%d child...\n",static_cast<int>(getpid()));
}


int main() {
    printf("pid=%d Enter main...\n",static_cast<int>(getpid()));
    //void (*)(void), void (*)(void), void (*)(void)
    // prepare, parent, child
    // 在fork之前，会先调用prepare，然后执行fork，在父进程中调用parent，在子进程中调用child
    pthread_atfork(prepare,parent,child);
    fork();
    printf("pid=%d Exit main...\n",static_cast<int>(getpid()));
    return 0;
}