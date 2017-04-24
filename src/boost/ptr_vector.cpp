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
    {
        // ptr_vector<A>::release returns a ptr_vector<A>::auto_type,
        // which is a kind of light-weight smart pointer in that when an auto_type item goes out of scope,
        // the thing it points to is automatically deleted.
        // To recover a raw pointer to the thing, and keep it from being deleted by the auto_ptr that's holding it,
        // you need to call release on that too:
        boost::ptr_vector<CMan> listMan;
        listMan.push_back(new CMan);
        CMan *temp=listMan.release(listMan.begin()).release();
        delete temp;
    }

    return 0;
}