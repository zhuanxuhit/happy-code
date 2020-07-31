//
// Created by 汪超 on 2020/7/28.
//
#include <type_traits>
#include <cstdio>

using namespace std;


#if __cplusplus == 201103L

// c++11
template<typename T>
struct has_reverse {
    struct good {
        char dummy;
    };
    struct bad {
        char dummy[2];
    };
    template<class U, void (U::*)(size_t)>
    struct SFINAE {
    };

    template<class U>
    static good
    reverse(SFINAE<U, &U::reverse> *);

    template<class U>
    static bad
    reverse(...);

    static const bool value = sizeof(reverse<T>(nullptr)) == sizeof(good);
};


template<typename C, typename T>
typename enable_if<has_reverse<C>::value, void>::type
append(C &container, T *ptr, size_t size) {
    container.reserve(container.size() + size);
    for (size_t i = 0; i < size; ++i) {
        container.push_back(ptr[i]);
    }
}

template<typename C, typename T>
typename enable_if<!has_reverse<C>::value, void>::type
append(C &container, T *ptr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        container.push_back(ptr[i]);
    }
}

#endif

#if __cplusplus == 201402L
// c++14

template <typename C, typename T>
auto append(C& container, T* ptr,
            size_t size)
  -> decltype(
    declval<C&>().reserve(1U),
    void())
{
  container.reserve(
    container.size() + size);
  for (size_t i = 0; i < size;
       ++i) {
    container.push_back(ptr[i]);
  }
}
#endif

#if __cplusplus == 201703L
// c++17

template<typename T,
        typename = void_t<>>
struct has_reserve : false_type {
};

template<typename T>
struct has_reserve<
        T, void_t<decltype(
        declval<T &>().reserve(1U))>>
        : true_type {
};


template<typename C, typename T>
void _append(C &container, T *ptr,
             size_t size,
             true_type) {
    container.reserve(
            container.size() + size);
    for (size_t i = 0; i < size;
         ++i) {
        container.push_back(ptr[i]);
    }
}

template<typename C, typename T>
void _append(C &container, T *ptr,
             size_t size,
             false_type) {
    for (size_t i = 0; i < size;
         ++i) {
        container.push_back(ptr[i]);
    }
}


template <typename C, typename T>
void append(C& container, T* ptr,
            size_t size)
{
    _append(
            container, ptr, size,
            has_reserve<C>{});
}

#endif