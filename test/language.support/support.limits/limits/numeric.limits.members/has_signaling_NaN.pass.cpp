//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// test numeric_limits

// has_signaling_NaN

#include <limits>

template <class T, bool expected>
void
test()
{
    static_assert(std::numeric_limits<T>::has_signaling_NaN == expected, "has_signaling_NaN test 1");
    static_assert(std::numeric_limits<const T>::has_signaling_NaN == expected, "has_signaling_NaN test 2");
    static_assert(std::numeric_limits<volatile T>::has_signaling_NaN == expected, "has_signaling_NaN test 3");
    static_assert(std::numeric_limits<const volatile T>::has_signaling_NaN == expected, "has_signaling_NaN test 4");
}

int main()
{
    test<bool, false>();
    test<char, false>();
    test<signed char, false>();
    test<unsigned char, false>();
    test<wchar_t, false>();
#ifndef _LIBCPP_HAS_NO_UNICODE_CHARS
    test<char16_t, false>();
    test<char32_t, false>();
#endif  // _LIBCPP_HAS_NO_UNICODE_CHARS
    test<short, false>();
    test<unsigned short, false>();
    test<int, false>();
    test<unsigned int, false>();
    test<long, false>();
    test<unsigned long, false>();
    test<long long, false>();
    test<unsigned long long, false>();
    test<float, true>();
    test<double, true>();
    test<long double, true>();
}
