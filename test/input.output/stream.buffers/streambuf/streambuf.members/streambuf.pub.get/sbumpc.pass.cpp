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

// int_type sbumpc();

#include <streambuf>
#include <cassert>

int uflow_called = 0;

struct test
    : public std::basic_streambuf<char>
{
    typedef std::basic_streambuf<char> base;

    test() {}

    void setg(char* gbeg, char* gnext, char* gend)
    {
        base::setg(gbeg, gnext, gend);
    }

protected:
    int_type uflow()
    {
        ++uflow_called;
        return 'a';
    }
};

int main()
{
    {
        test t;
        assert(uflow_called == 0);
        assert(t.sbumpc() == 'a');
        assert(uflow_called == 1);
        char in[] = "ABC";
        t.setg(in, in, in+sizeof(in));
        assert(t.sbumpc() == 'A');
        assert(uflow_called == 1);
        assert(t.sbumpc() == 'B');
        assert(uflow_called == 1);
    }
}
