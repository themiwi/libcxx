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

// template <class Rep1, class Period1, class Rep2, class Period2>
//   typename common_type<duration<Rep1, Period1>, duration<Rep2, Period2>>::type
//   operator+(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

#include <chrono>
#include <cassert>

int main()
{
    {
    std::chrono::seconds s1(3);
    std::chrono::seconds s2(5);
    std::chrono::seconds r = s1 + s2;
    assert(r.count() == 8);
    }
    {
    std::chrono::seconds s1(3);
    std::chrono::microseconds s2(5);
    std::chrono::microseconds r = s1 + s2;
    assert(r.count() == 3000005);
    }
    {
    std::chrono::duration<int, std::ratio<2, 3> > s1(3);
    std::chrono::duration<int, std::ratio<3, 5> > s2(5);
    std::chrono::duration<int, std::ratio<1, 15> > r = s1 + s2;
    assert(r.count() == 75);
    }
    {
    std::chrono::duration<int, std::ratio<2, 3> > s1(3);
    std::chrono::duration<double, std::ratio<3, 5> > s2(5);
    std::chrono::duration<double, std::ratio<1, 15> > r = s1 + s2;
    assert(r.count() == 75);
    }
}
