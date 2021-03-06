//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <regex>

// template <class charT, class traits = regex_traits<charT>> class basic_regex;

// basic_regex();

#include <regex>
#include <cassert>

template <class CharT>
void
test()
{
    std::basic_regex<CharT> r;
    assert(r.flags() == 0);
    assert(r.mark_count() == 0);
}

int main()
{
    test<char>();
    test<wchar_t>();
}
