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

// inexact conversions allowed for floating point reps

#include <chrono>
#include <cassert>

int main()
{
    std::chrono::duration<double, std::micro> us(1);
    std::chrono::duration<double, std::milli> ms = us;
    assert(ms.count() == 1./1000);
}
