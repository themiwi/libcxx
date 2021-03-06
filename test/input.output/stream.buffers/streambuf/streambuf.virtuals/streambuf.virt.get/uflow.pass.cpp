//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <streambuf>

// template <class charT, class traits = char_traits<charT> >
// class basic_streambuf;

// int_type uflow();

#include <streambuf>
#include <cassert>

int underflow_called = 0;

struct test
    : public std::basic_streambuf<char>
{
    test() {}

};

int main()
{
    test t;
    assert(t.sgetc() == -1);
}
