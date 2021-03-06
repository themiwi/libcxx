//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <chrono>

// system_clock

// rep should be signed

#include <chrono>
#include <cassert>

int main()
{
    assert(std::chrono::system_clock::duration::min() <
           std::chrono::system_clock::duration::zero());
}
