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

// template <class Rep2>
//   explicit duration(const Rep2& r);

// Rep2 shall be implicitly convertible to rep

#include <chrono>

#include "../../rep.h"

int main()
{
    std::chrono::duration<Rep> d(1);
}
