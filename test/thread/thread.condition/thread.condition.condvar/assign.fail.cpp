//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <condition_variable>

// class condition_variable;

// condition_variable& operator=(const condition_variable&) = delete;

#include <condition_variable>
#include <cassert>

int main()
{
    std::condition_variable cv0;
    std::condition_variable cv1;
    cv1 = cv0;
}
