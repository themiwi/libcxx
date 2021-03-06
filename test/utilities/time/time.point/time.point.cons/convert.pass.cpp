//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <chrono>

// time_point

// template <class Duration2>
//   time_point(const time_point<clock, Duration2>& t);

#include <chrono>
#include <cassert>

int main()
{
    typedef std::chrono::system_clock Clock;
    typedef std::chrono::microseconds Duration1;
    typedef std::chrono::milliseconds Duration2;
    {
    std::chrono::time_point<Clock, Duration2> t2(Duration2(3));
    std::chrono::time_point<Clock, Duration1> t1 = t2;
    assert(t1.time_since_epoch() == Duration1(3000));
    }
}
