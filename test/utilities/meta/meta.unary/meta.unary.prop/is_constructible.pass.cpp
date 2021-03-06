//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// type_traits

// template <class T, class... Args>
//   struct is_constructible;

#include <type_traits>

#ifndef _LIBCPP_HAS_NO_ADVANCED_SFINAE

struct A
{
    explicit A(int);
    A(int, double);
};

#endif  // _LIBCPP_HAS_NO_ADVANCED_SFINAE

int main()
{
#ifndef _LIBCPP_HAS_NO_ADVANCED_SFINAE

    static_assert((std::is_constructible<int>::value), "");
    static_assert((std::is_constructible<int, const int>::value), "");
    static_assert((std::is_constructible<A, int>::value), "");
    static_assert((std::is_constructible<A, int, double>::value), "");
    static_assert((!std::is_constructible<A>::value), "");

#endif  // _LIBCPP_HAS_NO_ADVANCED_SFINAE
}
