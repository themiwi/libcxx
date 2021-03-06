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

// static char_type* copy(char_type* s1, const char_type* s2, size_t n);

#include <string>
#include <cassert>

int main()
{
#ifndef _LIBCPP_HAS_NO_UNICODE_CHARS
    char32_t s1[] = {1, 2, 3};
    char32_t s2[3] = {0};
    assert(std::char_traits<char32_t>::copy(s2, s1, 3) == s2);
    assert(s2[0] == char32_t(1));
    assert(s2[1] == char32_t(2));
    assert(s2[2] == char32_t(3));
#endif  // _LIBCPP_HAS_NO_UNICODE_CHARS
}
