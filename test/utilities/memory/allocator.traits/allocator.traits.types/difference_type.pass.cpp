//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// template <class Alloc>
// struct allocator_traits
// {
//     typedef Alloc::difference_type
//           | ptrdiff_t                    difference_type;
//     ...
// };

#include <memory>
#include <type_traits>

template <class T>
struct A
{
    typedef T value_type;
    typedef short difference_type;
};

template <class T>
struct B
{
    typedef T value_type;
};

int main()
{
    static_assert((std::is_same<std::allocator_traits<A<char> >::difference_type, short>::value), "");
    static_assert((std::is_same<std::allocator_traits<B<char> >::difference_type, std::ptrdiff_t>::value), "");
}
