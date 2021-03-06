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

// duration& operator--();

#include <chrono>
#include <cassert>

int main()
{
    std::chrono::hours h(3);
    std::chrono::hours& href = --h;
    assert(&href == &h);
    assert(h.count() == 2);
}
