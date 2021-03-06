//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// template <class T, class Alloc> struct uses_allocator;

#include <memory>
#include <vector>

struct A
{
};

struct B
{
    typedef int allocator_type;
};

int main()
{
    static_assert((!std::uses_allocator<int, std::allocator<int> >::value), "");
    static_assert(( std::uses_allocator<std::vector<int>, std::allocator<int> >::value), "");
    static_assert((!std::uses_allocator<A, std::allocator<int> >::value), "");
    static_assert((!std::uses_allocator<B, std::allocator<int> >::value), "");
    static_assert(( std::uses_allocator<B, double>::value), "");
}
