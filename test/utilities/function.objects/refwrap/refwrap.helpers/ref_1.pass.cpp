//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <functional>

// reference_wrapper

// template <ObjectType T> reference_wrapper<T> ref(T& t);

#include <functional>
#include <cassert>

int main()
{
    int i = 0;
    std::reference_wrapper<int> r = std::ref(i);
    assert(&r.get() == &i);
}
