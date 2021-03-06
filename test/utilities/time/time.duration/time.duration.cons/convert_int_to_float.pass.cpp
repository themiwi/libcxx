//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <chrono>

// duration

// template <class Rep2, class Period2>
//   duration(const duration<Rep2, Period2>& d);

//  conversions from integral to floating point durations allowed

#include <chrono>
#include <cassert>

int main()
{
    std::chrono::duration<int> i(3);
    std::chrono::duration<int> d = i;
    assert(d.count() == 3);
}
