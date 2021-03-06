//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <random>

// typedef subtract_with_carry_engine<uint_fast64_t, 48,  5, 12>  ranlux48_base;

#include <random>
#include <cassert>

int main()
{
    std::ranlux48_base e;
    e.discard(9999);
    assert(e() == 61839128582725ull);
}
