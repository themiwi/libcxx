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

// Test default template arg:

// template <class Rep, class Period = ratio<1>>
// class duration;

#include <chrono>
#include <type_traits>

int main()
{
    static_assert((std::is_same<std::chrono::duration<int, std::ratio<1> >,
                   std::chrono::duration<int> >::value), "");
}
