//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <iterator>

// class ostreambuf_iterator

// ostreambuf_iterator<charT,traits>& operator*();

#include <iterator>
#include <sstream>
#include <cassert>

int main()
{
    {
        std::ostringstream outf;
        std::ostreambuf_iterator<char> i(outf);
        std::ostreambuf_iterator<char>& iref = *i;
        assert(&iref == &i);
    }
    {
        std::wostringstream outf;
        std::ostreambuf_iterator<wchar_t> i(outf);
        std::ostreambuf_iterator<wchar_t>& iref = *i;
        assert(&iref == &i);
    }
}
