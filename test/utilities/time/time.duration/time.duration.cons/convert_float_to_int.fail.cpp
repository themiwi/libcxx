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

//  conversions from floating point to integral durations disallowed

#include <chrono>

int main()
{
    std::chrono::duration<double> d;
    std::chrono::duration<int> i = d;
}
