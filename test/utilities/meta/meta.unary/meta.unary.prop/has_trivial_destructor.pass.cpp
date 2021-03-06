//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// type_traits

// has_trivial_destructor

#include <type_traits>

template <class T>
void test_has_trivial_destructor()
{
    static_assert( std::has_trivial_destructor<T>::value, "");
    static_assert( std::has_trivial_destructor<const T>::value, "");
    static_assert( std::has_trivial_destructor<volatile T>::value, "");
    static_assert( std::has_trivial_destructor<const volatile T>::value, "");
}

template <class T>
void test_has_not_trivial_destructor()
{
    static_assert(!std::has_trivial_destructor<T>::value, "");
    static_assert(!std::has_trivial_destructor<const T>::value, "");
    static_assert(!std::has_trivial_destructor<volatile T>::value, "");
    static_assert(!std::has_trivial_destructor<const volatile T>::value, "");
}

class Empty
{
};

class NotEmpty
{
    virtual ~NotEmpty();
};

union Union {};

struct bit_zero
{
    int :  0;
};

class Abstract
{
    virtual ~Abstract() = 0;
};

struct A
{
    ~A();
};

int main()
{
    test_has_not_trivial_destructor<void>();
    test_has_not_trivial_destructor<A>();
    test_has_not_trivial_destructor<Abstract>();
    test_has_not_trivial_destructor<NotEmpty>();

    test_has_trivial_destructor<int&>();
    test_has_trivial_destructor<Union>();
    test_has_trivial_destructor<Empty>();
    test_has_trivial_destructor<int>();
    test_has_trivial_destructor<double>();
    test_has_trivial_destructor<int*>();
    test_has_trivial_destructor<const int*>();
    test_has_trivial_destructor<char[3]>();
    test_has_trivial_destructor<char[3]>();
    test_has_trivial_destructor<bit_zero>();
}
