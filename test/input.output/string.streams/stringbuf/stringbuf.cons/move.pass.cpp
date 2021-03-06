//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <sstream>

// template <class charT, class traits = char_traits<charT>, class Allocator = allocator<charT> >
// class basic_stringbuf

// basic_stringbuf(basic_stringbuf&& rhs);

#include <sstream>
#include <cassert>

int main()
{
    {
        std::stringbuf buf1("testing");
        std::stringbuf buf(move(buf1));
        assert(buf.str() == "testing");
    }
    {
        std::stringbuf buf1("testing", std::ios_base::in);
        std::stringbuf buf(move(buf1));
        assert(buf.str() == "testing");
    }
    {
        std::stringbuf buf1("testing", std::ios_base::out);
        std::stringbuf buf(move(buf1));
        assert(buf.str() == "testing");
    }
    {
        std::wstringbuf buf1(L"testing");
        std::wstringbuf buf(move(buf1));
        assert(buf.str() == L"testing");
    }
    {
        std::wstringbuf buf1(L"testing", std::ios_base::in);
        std::wstringbuf buf(move(buf1));
        assert(buf.str() == L"testing");
    }
    {
        std::wstringbuf buf1(L"testing", std::ios_base::out);
        std::wstringbuf buf(move(buf1));
        assert(buf.str() == L"testing");
    }
}
