现代C++实战30讲笔记



## c++智能指针

- 知识点：new 和 delete 原理

- RAII（Resource Acquisition Is Initialization）



## 知识点

### [big of three](https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three) and **a Half**

c++11之前有3个：

- copy constructor
- copy assignment
- destructor

c++11之后新增了2个

- move constructor
- move assignment

```cpp
class person
{
    std::string name;
    int age;

public:
    person(const std::string& name, int age);        // Ctor
    person(const person &) = default;                // Copy Ctor
    person(person &&) noexcept = default;            // Move Ctor
    person& operator=(const person &) = default;     // Copy Assignment
    person& operator=(person &&) noexcept = default; // Move Assignment
    ~person() noexcept = default;                    // Dtor
};
```

当我们都不主动声明的时候，会给我们默认的实现。

另外有一个 A Half

- 提供swap函数，此处swap的作用就是下面的copy and swap idiom中介绍的

另外我们可以将move assigment和copy assigment合并为一个：

```c++
person& operator=(person rhs){// Copy Assignment
	std::swap(*this, rhs)
	return *this
}
```



### Copy and swap idiom

使用**copy-and-swap**需要三件事情：

- a working copy-constructor
- a working desctrctor
- a swap function：a *non-throwing* function that swaps two objects of a class

### 单一资源原则

每个类只管理一个资源

### [什么是move semantics](https://stackoverflow.com/questions/3106110/what-is-move-semantics)

> To move an object means to transfer ownership of some resource it manages to another object.

c++11引入了左值和右值的概念，

- 左值（X&），移动是危险的，应该要复制
- 右值（X&&），可以放心的将其资源移交给其他人

```cpp
            lvalue   const lvalue   rvalue   const rvalue
---------------------------------------------------------              
X&          yes
const X&    yes      yes            yes      yes
X&&                                 yes
const X&&                           yes      yes
```



> An rvalue reference `X&&` is a new kind of reference that only binds to rvalues.



#### [moving from lvalues](https://stackoverflow.com/questions/3106110/what-is-move-semantics/11540204#11540204)

`std::move`将左值转换为右值

#### Moving out of functions

```cpp
unique_ptr<Shape> make_triangle()
{
    return unique_ptr<Shape>(new Triangle);
}          \-----------------------------/
                  |
                  | temporary is moved into c
                  |
                  v
unique_ptr<Shape> c(make_triangle());
```

这个叫：**"named return value optimization" (NRVO)** 优化。

#### Moving into members

```cpp
class Foo
{
    unique_ptr<Shape> member;

public:

    Foo(unique_ptr<Shape>&& parameter)
    : member(std::move(parameter))   // note the std::move
    {}
};
```

此处虽然`parameter`被声明为右值，但是`parameter`本身是普通的变量，需要转换为右值。

#### Forwarding references

```cpp
template<typename T>
void foo(T&&);
```

即使声明为了`T&&`，但是也可能最后也会绑定到lvalue上

```cpp
// unique_ptr<Shape> make_triangle();
foo(make_triangle());   // T is unique_ptr<Shape>, T&& is unique_ptr<Shape>&&
unique_ptr<Shape> a(new Triangle);
foo(a);                 // T is unique_ptr<Shape>&, T&& is unique_ptr<Shape>&
```

> T&& is not an rvalue reference, but a forwarding reference. It also binds to lvalues, in which case `T` and `T&&` are both lvalue references.

> since C++ still has no notion of references to references, the type `X& &&` is *collapsed* into `X&`. 

**如何严格声明为rvalue**

```cpp
#include <type_traits>

template<typename T>
typename std::enable_if<std::is_rvalue_reference<T&&>::value, void>::type
foo(T&&);
```



### auto_ptr 被 c++11 中的 unique_ptr 代替

auto_ptr 的拷贝构造，其实是移动，非常危险

### **Universal vs Forwarding References in C++**

```cpp
void foo(int && i);
template<typename T>
void bar(T&& i);
```

Forwarding References代表即可表示lvalue，又可以rvalue

#### **[public friend swap member function](https://stackoverflow.com/questions/5695548/public-friend-swap-member-function)**

