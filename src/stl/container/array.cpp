//
// Created by zhuanxu on 2018/4/17.
//

const long ASIZE = 500000L;

#include <iostream>

using namespace std;
using std::cin;
using std::cout;


string getCpuTime(clock_t timeStart) {
    double elapsed =  1000.0 * (timeStart - clock()) / CLOCKS_PER_SEC;

}

//-----------------
long get_a_target_long() {
    long target = 0;

    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    return target;
}

string get_a_target_string() {
    long target = 0;
    char buf[10];

    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    snprintf(buf, 10, "%ld", target);
    return string(buf);
}

int compareLongs(const void *a, const void *b) {
    return static_cast<int>(*(long *) a - *(long *) b);
}


int compareStrings(const void *a, const void *b) {
    if (*(string *) a > *(string *) b)
        return 1;
    else if (*(string *) a < *(string *) b)
        return -1;
    else
        return 0;
}


//---------------------------------------------------
#include <array>

namespace jj01 {
    void test_array() {
        cout << "\ntest_array()...........\n";
        array<long, ASIZE> c;

        clock_t timeStart = clock();
        for (long i = 0; i < ASIZE; i++) {
            c[i] = rand();
        }
        cout << "milli-seconds : " << getCpuTime(timeStart) << endl;    //
        cout << "array.size()= " << c.size() << endl;
        cout << "array.front()= " << c.front() << endl;
        cout << "array.back()= " << c.back() << endl;
        cout << "array.data()= " << c.data() << endl;

        long target = get_a_target_long();

        timeStart = clock();
        ::qsort(c.data(), ASIZE, sizeof(long), compareLongs);
        long *pItem = static_cast<long *>(::bsearch(&target, c.data(), ASIZE, sizeof(long), compareLongs));
        cout << "qsort()+bsearch(), milli-seconds : " << getCpuTime(timeStart) << endl;    //
        if (pItem != NULL)
            cout << "found, " << *pItem << endl;
        else
            cout << "not found! " << endl;
    }
}
//---------------------------------------------------

#include <vector>

namespace jj02 {
    void test_vector(long &value) {
        cout << "\ntest_vector()...........\n";
        // 1. 生成字符串vector
        vector<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0; i < value; i++) {
            try {
                snprintf(buf, 10, "%d", rand());
                c.emplace_back(buf);
            } catch (exception &e) {
                // 此处异常的可能性是vector内部在扩展内部容量的时候，出现内存不足的情况
                cout << "i=" << i << " " << e.what() << endl;
                abort();
            }
        }
        // 统计时间
        cout << "milli-seconds: " << getCpuTime(timeStart) << endl;
        cout << "vector.max_size()= " << c.max_size() << endl;    //1073747823
        cout << "vector.size()= " << c.size() << endl;
        cout << "vector.front()= " << c.front() << endl;
        cout << "vector.back()= " << c.back() << endl;
        cout << "vector.data()= " << c.data() << endl;
        cout << "vector.capacity()= " << c.capacity() << endl << endl;
        // 2. 查找目标字符串，按照线性查找和二分查找来做
        string target = get_a_target_string();
        timeStart = clock();
        auto pItem = ::find(c.begin(), c.end(), target);
        cout << "::find(), milli-seconds : " << getCpuTime(timeStart) << endl;    //
        if (pItem == c.end()) {
            // 没找到
            cout << "not found! " << endl;
        } else {
            cout << "found, " << *pItem << endl;
        }
        // 下面开始先排序，在查找
        timeStart = clock();
        {
            ::sort(c.begin(), c.end());
            string *pitem = static_cast<string *>(::bsearch(&target, c.data(), c.size(), sizeof(string), compareStrings));
            cout << "sort()+bsearch() milli-seconds : " << getCpuTime(timeStart) << endl;    //
            if (pitem == nullptr) {
                // 没找到
                cout << "not found! " << endl;
            } else {
                cout << "found, " << *pitem << endl;
            }
        }
    }
}


//---------------------------------------------------
#include <list>

namespace jj03 {
    void test_long(long &value) {
        cout << "\ntest_long()........\n";
        clock_t timeStart = clock();
        list<string> c;
        char buf[10];
        for(long i=0;i<value;i++){
            try{
                snprintf(buf,10,"%d",rand());
                c.emplace_back(string(buf));
            }catch (exception &e){
                cout << "i=" << i << " " << e.what() << endl;
                abort();
            }
        }
        cout << "milli-seconds : " << getCpuTime(timeStart) << endl;
        cout << "list.size()= " << c.size() << endl;
        cout << "list.max_size()= " << c.max_size() << endl;    //357913941
        cout << "list.front()= " << c.front() << endl;
        cout << "list.back()= " << c.back() << endl;

        string target = get_a_target_string();
        timeStart = clock();
        auto pItem =  ::find(c.begin(),c.end(),target);
        cout << "::find(), milli-seconds : " << getCpuTime(timeStart) << endl;    //
        if (pItem == c.end()) {
            // 没找到
            cout << "not found! " << endl;
        } else {
            cout << "found, " << *pItem << endl;
        }
        // 开始对数据进行sort
        timeStart = clock();
        c.sort();
//        sort(c.begin(),c.end());
        cout << "c.sort(), milli-seconds : " << getCpuTime(timeStart) << endl;    //
    }
}

int main() {
//    jj01::test_array();
    long value = ASIZE;
//    jj02::test_vector(value);
    jj03::test_long(value);
}

