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

// static time_point now();

#include <chrono>

int main()
{
    typedef std::chrono::system_clock C;
    C::time_point t1 = C::now();
}
