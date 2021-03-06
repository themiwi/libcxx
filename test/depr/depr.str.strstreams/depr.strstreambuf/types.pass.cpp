//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <strstream>

// class strstreambuf
//     : public basic_streambuf<char>

#include <strstream>
#include <type_traits>

int main()
{
    static_assert((std::is_base_of<std::streambuf, std::strstreambuf>::value), "");
}
