//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// template <class Ptr>
// struct pointer_traits
// {
//     typedef Ptr pointer;
//     ...
// };

#include <memory>
#include <type_traits>

struct A
{
    typedef short element_type;
    typedef char difference_type;
};

int main()
{
    static_assert((std::is_same<std::pointer_traits<A>::pointer, A>::value), "");
    static_assert((std::is_same<std::pointer_traits<int*>::pointer, int*>::value), "");
}
