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

// duration& operator*=(const rep& rhs);

#include <chrono>
#include <cassert>

int main()
{
    std::chrono::nanoseconds ns(3);
    ns *= 5;
    assert(ns.count() == 15);
}
