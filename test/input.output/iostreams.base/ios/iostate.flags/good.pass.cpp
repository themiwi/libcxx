//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <ios>

// template <class charT, class traits> class basic_ios

// bool good() const;

#include <ios>
#include <streambuf>
#include <cassert>

struct testbuf : public std::streambuf {};

int main()
{
    {
        std::ios ios(0);
        assert(!ios.good());
    }
    {
        testbuf sb;
        std::ios ios(&sb);
        assert(ios.good());
        ios.setstate(std::ios::eofbit);
        assert(!ios.good());
    }
}
