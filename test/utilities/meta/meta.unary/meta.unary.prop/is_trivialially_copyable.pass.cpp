//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// type_traits

// is_trivially_copyable

#include <type_traits>
#include <cassert>

struct A
{
    int i_;
};

struct B
{
    int i_;
    ~B() {assert(i_ == 0);}
};

int main()
{
    static_assert( std::is_trivially_copyable<int>::value, "");
    static_assert( std::is_trivially_copyable<const int>::value, "");
    static_assert(!std::is_trivially_copyable<int&>::value, "");
    static_assert( std::is_trivially_copyable<A>::value, "");
    static_assert( std::is_trivially_copyable<const A>::value, "");
    static_assert(!std::is_trivially_copyable<const A&>::value, "");
    static_assert(!std::is_trivially_copyable<B>::value, "");
}
