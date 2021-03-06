//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// type_traits

// enable_if

#include <type_traits>

int main()
{
    typedef std::enable_if<false>::type A;
}
