//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// type_traits

// is_same

#include <type_traits>

template <class T, class U>
void test_is_same()
{
    static_assert((std::is_same<T, U>::value), "");
    static_assert((!std::is_same<const T, U>::value), "");
    static_assert((!std::is_same<T, const U>::value), "");
    static_assert((std::is_same<const T, const U>::value), "");
}

template <class T, class U>
void test_is_same_ref()
{
    static_assert((std::is_same<T, U>::value), "");
    static_assert((std::is_same<const T, U>::value), "");
    static_assert((std::is_same<T, const U>::value), "");
    static_assert((std::is_same<const T, const U>::value), "");
}

template <class T, class U>
void test_is_not_same()
{
    static_assert((!std::is_same<T, U>::value), "");
}

class Class
{
public:
    ~Class();
};

int main()
{
    test_is_same<int, int>();
    test_is_same<void, void>();
    test_is_same<Class, Class>();
    test_is_same<int*, int*>();
    test_is_same_ref<int&, int&>();

    test_is_not_same<int, void>();
    test_is_not_same<void, Class>();
    test_is_not_same<Class, int*>();
    test_is_not_same<int*, int&>();
    test_is_not_same<int&, int>();
}
