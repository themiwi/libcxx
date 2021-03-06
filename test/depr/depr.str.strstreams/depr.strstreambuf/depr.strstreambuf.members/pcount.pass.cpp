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

// int pcount() const;

#include <strstream>
#include <cassert>

int main()
{
    {
        std::strstreambuf sb;
        assert(sb.pcount() == 0);
        assert(sb.sputc('a') == 'a');
        assert(sb.pcount() == 1);
        assert(sb.sputc(0) == 0);
        assert(sb.pcount() == 2);
        assert(sb.str() == std::string("a"));
        assert(sb.pcount() == 2);
    }
}
