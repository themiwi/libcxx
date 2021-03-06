//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <functional>

// unary_function

#include <functional>
#include <type_traits>

int main()
{
    typedef std::unary_function<int, bool> uf;
    static_assert((std::is_same<uf::argument_type, int>::value), "");
    static_assert((std::is_same<uf::result_type, bool>::value), "");
}
