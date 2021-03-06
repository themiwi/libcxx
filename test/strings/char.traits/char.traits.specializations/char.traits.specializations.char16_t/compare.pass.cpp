//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// template<> struct char_traits<char16_t>

// static int compare(const char_type* s1, const char_type* s2, size_t n);

#include <string>
#include <cassert>

int main()
{
#ifndef _LIBCPP_HAS_NO_UNICODE_CHARS
    assert(std::char_traits<char16_t>::compare(u"", u"", 0) == 0);

    assert(std::char_traits<char16_t>::compare(u"1", u"1", 1) == 0);
    assert(std::char_traits<char16_t>::compare(u"1", u"2", 1) < 0);
    assert(std::char_traits<char16_t>::compare(u"2", u"1", 1) > 0);

    assert(std::char_traits<char16_t>::compare(u"12", u"12", 2) == 0);
    assert(std::char_traits<char16_t>::compare(u"12", u"13", 2) < 0);
    assert(std::char_traits<char16_t>::compare(u"12", u"22", 2) < 0);
    assert(std::char_traits<char16_t>::compare(u"13", u"12", 2) > 0);
    assert(std::char_traits<char16_t>::compare(u"22", u"12", 2) > 0);

    assert(std::char_traits<char16_t>::compare(u"123", u"123", 3) == 0);
    assert(std::char_traits<char16_t>::compare(u"123", u"223", 3) < 0);
    assert(std::char_traits<char16_t>::compare(u"123", u"133", 3) < 0);
    assert(std::char_traits<char16_t>::compare(u"123", u"124", 3) < 0);
    assert(std::char_traits<char16_t>::compare(u"223", u"123", 3) > 0);
    assert(std::char_traits<char16_t>::compare(u"133", u"123", 3) > 0);
    assert(std::char_traits<char16_t>::compare(u"124", u"123", 3) > 0);
#endif  // _LIBCPP_HAS_NO_UNICODE_CHARS
}
