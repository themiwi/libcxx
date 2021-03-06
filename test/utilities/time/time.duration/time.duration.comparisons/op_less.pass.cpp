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
//   bool
//   operator< (const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

// template <class Rep1, class Period1, class Rep2, class Period2>
//   bool
//   operator> (const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

// template <class Rep1, class Period1, class Rep2, class Period2>
//   bool
//   operator<=(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

// template <class Rep1, class Period1, class Rep2, class Period2>
//   bool
//   operator>=(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

#include <chrono>
#include <cassert>

int main()
{
    {
    std::chrono::seconds s1(3);
    std::chrono::seconds s2(3);
    assert(!(s1 < s2));
    assert(!(s1 > s2));
    assert( (s1 <= s2));
    assert( (s1 >= s2));
    }
    {
    std::chrono::seconds s1(3);
    std::chrono::seconds s2(4);
    assert( (s1 < s2));
    assert(!(s1 > s2));
    assert( (s1 <= s2));
    assert(!(s1 >= s2));
    }
    {
    std::chrono::milliseconds s1(3);
    std::chrono::microseconds s2(3000);
    assert(!(s1 < s2));
    assert(!(s1 > s2));
    assert( (s1 <= s2));
    assert( (s1 >= s2));
    }
    {
    std::chrono::milliseconds s1(3);
    std::chrono::microseconds s2(4000);
    assert( (s1 < s2));
    assert(!(s1 > s2));
    assert( (s1 <= s2));
    assert(!(s1 >= s2));
    }
    {
    std::chrono::duration<int, std::ratio<2, 3> > s1(9);
    std::chrono::duration<int, std::ratio<3, 5> > s2(10);
    assert(!(s1 < s2));
    assert(!(s1 > s2));
    assert( (s1 <= s2));
    assert( (s1 >= s2));
    }
    {
    std::chrono::duration<int, std::ratio<2, 3> > s1(10);
    std::chrono::duration<int, std::ratio<3, 5> > s2(9);
    assert(!(s1 < s2));
    assert( (s1 > s2));
    assert(!(s1 <= s2));
    assert( (s1 >= s2));
    }
    {
    std::chrono::duration<int, std::ratio<2, 3> > s1(9);
    std::chrono::duration<double, std::ratio<3, 5> > s2(10);
    assert(!(s1 < s2));
    assert(!(s1 > s2));
    assert( (s1 <= s2));
    assert( (s1 >= s2));
    }
}
