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

// explicit strstreambuf(streamsize alsize_arg = 0);

#include <strstream>
#include <cassert>

int main()
{
    {
        std::strstreambuf s;
        assert(s.str() == nullptr);
        assert(s.pcount() == 0);
    }
    {
        std::strstreambuf s(1024);
        assert(s.str() == nullptr);
        assert(s.pcount() == 0);
    }
}
