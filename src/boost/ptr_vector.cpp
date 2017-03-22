//
// Created by zhuanxu on 17/3/22.
//
#include <boost/ptr_container/ptr_container.hpp>


#include "stdlib.h"

class CMan {
public:
    CMan() {
        printf("construct\n");
    }

    ~CMan() {
        printf("deconstruct\n");
    }

protected:
private:
};

int main() {
    {
        // 帮我们管理指针，调用析构函数
        boost::ptr_vector<CMan> listMan;
        CMan *p1 = new CMan();
        listMan.push_back(p1);
    }
    return 0;
}