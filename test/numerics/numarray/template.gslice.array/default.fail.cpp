//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <valarray>

// template <class T> class gslice_array

// gslice_array() = delete;

#include <valarray>
#include <type_traits>

int main()
{
    std::gslice_array<int> gs;
}
