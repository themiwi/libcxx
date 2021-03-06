//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// type_traits

// is_standard_layout

#include <type_traits>

int main()
{
    static_assert( std::is_standard_layout<int>::value, "");
    static_assert(!std::is_standard_layout<int&>::value, "");
    static_assert(!std::is_standard_layout<volatile int&>::value, "");
}
