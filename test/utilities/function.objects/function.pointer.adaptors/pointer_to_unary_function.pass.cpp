//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <functional>

// pointer_to_unary_function

#include <functional>
#include <type_traits>
#include <cassert>

double unary_f(int i) {return 0.5 - i;}

int main()
{
    typedef std::pointer_to_unary_function<int, double> F;
    static_assert((std::is_base_of<std::unary_function<int, double>, F>::value), "");
    const F f(unary_f);
    assert(f(36) == -35.5);
}
