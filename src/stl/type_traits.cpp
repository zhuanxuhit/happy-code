//
// Created by zhuanxu on 17/3/1.
//

#include <type_traits>
#include <vector>
#include <array>
#include <iostream>
using namespace std;

// 为什么新的 type_traits 不需要每个 type 都需去做偏特化了呢
// 模板拿到了 type 后，会先将一些无关紧要的东西去掉，譬如 const，volatile

template <typename T>
void type_traits_output(const T& x)
{
    cout << "\ntype traits for type : " << typeid(T).name() << endl;

    cout << "is_void\t" << is_void<T>::value << endl;
    cout << "is_integral\t" << is_integral<T>::value << endl;
    cout << "is_floating_point\t" << is_floating_point<T>::value << endl;
    cout << "is_arithmetic\t" << is_arithmetic<T>::value << endl;
    cout << "is_signed\t" << is_signed<T>::value << endl;
    cout << "is_unsigned\t" << is_unsigned<T>::value << endl;
    cout << "is_const\t" << is_const<T>::value << endl;
    cout << "is_volatile\t" << is_volatile<T>::value << endl;
    cout << "is_class\t" << is_class<T>::value << endl;
    cout << "is_function\t" << is_function<T>::value << endl;
    cout << "is_reference\t" << is_reference<T>::value << endl;
    cout << "is_lvalue_reference\t" << is_lvalue_reference<T>::value << endl;
    cout << "is_rvalue_reference\t" << is_rvalue_reference<T>::value << endl;
    cout << "is_pointer\t" << is_pointer<T>::value << endl;
    cout << "is_member_pointer\t" << is_member_pointer<T>::value << endl;
    cout << "is_member_object_pointer\t" << is_member_object_pointer<T>::value << endl;
    cout << "is_member_function_pointer\t" << is_member_function_pointer<T>::value << endl;
    cout << "is_fundamental\t" << is_fundamental<T>::value << endl;
    cout << "is_scalar\t" << is_scalar<T>::value << endl;
    cout << "is_object\t" << is_object<T>::value << endl;
    cout << "is_compound\t" << is_compound<T>::value << endl;
    cout << "is_standard_layout\t" << is_standard_layout<T>::value << endl;
    cout << "is_pod\t" << is_pod<T>::value << endl;
    cout << "is_literal_type\t" << is_literal_type<T>::value << endl;
    cout << "is_empty\t" << is_empty<T>::value << endl;
    cout << "is_polymorphic\t" << is_polymorphic<T>::value << endl;
    cout << "is_abstract\t" << is_abstract<T>::value << endl;
    cout << "has_virtual_destructor\t" << has_virtual_destructor<T>::value << endl;
    cout << "is_default_constructible\t" << is_default_constructible<T>::value << endl;
    cout << "is_copy_constructible\t" << is_copy_constructible<T>::value << endl;
    cout << "is_move_constructible\t" << is_move_constructible<T>::value << endl;
    cout << "is_copy_assignable\t" << is_copy_assignable<T>::value << endl;
    cout << "is_move_assignable\t" << is_move_assignable<T>::value << endl;
    cout << "is_destructible\t" << is_destructible<T>::value << endl;
    cout << "is_trivial\t" << is_trivial<T>::value << endl;
	cout << "is_trivially_constructible\t" << is_trivially_constructible<T>::value << endl; 	//[Error] was not declared in this scope
//!	cout << "has_trivial_constructor\t" << __has_trivial_constructor<T>::value << endl; 	//[Error] was not declared in this scope
//!	cout << "is_trivially_copyable\t" << is_trivially_copyable<T>::value << endl;  				//[Error] was not declared in this scope
//!	cout << "is_trivially_default_constructible\t" << is_trivially_default_constructible<T>::value << endl;
//!	cout << "is_trivially_copy_constructible\t" << is_trivially_copy_constructible<T>::value << endl;
//!	cout << "is_trivially_move_constructible\t" << is_trivially_move_constructible<T>::value << endl;
//!	cout << "is_trivially_copy_assignable\t" << is_trivially_copy_assignable<T,int>::value << endl; 	//注意, 需要兩個 template type param.
//!	cout << "is_trivially_move_assignable\t" << is_trivially_move_assignable<T,string>::value << endl; 	//注意, 需要兩個 template type param.

    //The C++ front end implements syntactic extensions that allow compile-time determination of
    //various characteristics of a type (or of a pair of types).
    cout << "__has_trivial_assign\t" << __has_trivial_assign(T) << endl;
    cout << "__has_trivial_copy\t" << __has_trivial_copy(T) << endl;
    cout << "__has_trivial_constructor\t" << __has_trivial_constructor(T) << endl;
    cout << "__has_trivial_destructor\t" << __has_trivial_destructor(T) << endl;

    cout << "is_trivially_destructible\t" << is_trivially_destructible<T>::value << endl;
    cout << "is_nothrow_default_constructible\t" << is_nothrow_default_constructible<T>::value << endl;
    cout << "is_nothrow_copy_constructible\t" << is_nothrow_copy_constructible<T>::value << endl;
    cout << "is_nothrow_move_constructible\t" << is_nothrow_move_constructible<T>::value << endl;
    cout << "is_nothrow_copy_assignable\t" << is_nothrow_copy_assignable<T>::value << endl;
    cout << "is_nothrow_move_assignable\t" << is_nothrow_move_assignable<T>::value << endl;
    cout << "is_nothrow_destructible\t" << is_nothrow_destructible<T>::value << endl;
}


int main(){
    array<int,2> a = {1,2};
    cout << is_array<decltype(a)>::value << endl;
    cout << is_void<decltype(a)>::value  << endl;
    cout << is_class<decltype(a)>::value << endl;
    typedef decltype(a) VType;
    type_traits_output(a);
    VType b;
}