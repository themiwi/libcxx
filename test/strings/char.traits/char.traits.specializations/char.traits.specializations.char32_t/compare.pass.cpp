//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// template<> struct char_traits<char32_t>

// static int compare(const char_type* s1, const char_type* s2, size_t n);

#include <string>
#include <cassert>

int main()
{
#ifndef _LIBCPP_HAS_NO_UNICODE_CHARS
    assert(std::char_traits<char32_t>::compare(U"", U"", 0) == 0);

    assert(std::char_traits<char32_t>::compare(U"1", U"1", 1) == 0);
    assert(std::char_traits<char32_t>::compare(U"1", U"2", 1) < 0);
    assert(std::char_traits<char32_t>::compare(U"2", U"1", 1) > 0);

    assert(std::char_traits<char32_t>::compare(U"12", U"12", 2) == 0);
    assert(std::char_traits<char32_t>::compare(U"12", U"13", 2) < 0);
    assert(std::char_traits<char32_t>::compare(U"12", U"22", 2) < 0);
    assert(std::char_traits<char32_t>::compare(U"13", U"12", 2) > 0);
    assert(std::char_traits<char32_t>::compare(U"22", U"12", 2) > 0);

    assert(std::char_traits<char32_t>::compare(U"123", U"123", 3) == 0);
    assert(std::char_traits<char32_t>::compare(U"123", U"223", 3) < 0);
    assert(std::char_traits<char32_t>::compare(U"123", U"133", 3) < 0);
    assert(std::char_traits<char32_t>::compare(U"123", U"124", 3) < 0);
    assert(std::char_traits<char32_t>::compare(U"223", U"123", 3) > 0);
    assert(std::char_traits<char32_t>::compare(U"133", U"123", 3) > 0);
    assert(std::char_traits<char32_t>::compare(U"124", U"123", 3) > 0);
#endif  // _LIBCPP_HAS_NO_UNICODE_CHARS
}
