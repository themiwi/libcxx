//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// template<class T> class shared_ptr
// {
// public:
//     typedef T element_type;
//     ...
// };

#include <memory>

struct A;  // purposefully incomplete

int main()
{
    static_assert((std::is_same<std::shared_ptr<A>::element_type, A>::value), "");
}
