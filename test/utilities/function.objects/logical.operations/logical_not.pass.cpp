//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <functional>

// logical_not

#include <functional>
#include <type_traits>
#include <cassert>

int main()
{
    typedef std::logical_not<int> F;
    const F f = F();
    static_assert((std::is_base_of<std::unary_function<int, bool>, F>::value), "");
    assert(!f(36));
    assert(f(0));
}
