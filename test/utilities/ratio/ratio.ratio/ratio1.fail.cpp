//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// test ratio:  The template argument D shall not be zero

#include <ratio>
#include <cstdint>

int main()
{
    const std::intmax_t t1 = std::ratio<1, 0>::num;
}
