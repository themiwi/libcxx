//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <fstream>

// template <class charT, class traits = char_traits<charT> >
// class basic_ifstream

// basic_ifstream();

#include <fstream>
#include <type_traits>

int main()
{
    {
        std::ifstream fs;
    }
    {
        std::wifstream fs;
    }
}
