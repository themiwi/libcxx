//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// template <class T>
// struct pointer_traits<T*>
// {
//     typedef ptrdiff_t difference_type;
//     ...
// };

#include <memory>
#include <type_traits>

int main()
{
    static_assert((std::is_same<std::pointer_traits<double*>::difference_type, std::ptrdiff_t>::value), "");
}
