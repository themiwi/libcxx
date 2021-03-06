//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <regex>

// class match_results<BidirectionalIterator, Allocator>

// const_iterator cbegin() const;
// const_iterator cend() const;

#include <regex>
#include <cassert>

void
test()
{
    std::match_results<const char*> m;
    const char s[] = "abcdefghijk";
    assert(std::regex_search(s, m, std::regex("cd((e)fg)hi")));

    std::match_results<const char*>::const_iterator i = m.cbegin();
    std::match_results<const char*>::const_iterator e = m.cend();

    assert(e - i == m.size() - 1);
    for (int j = 1; i != e; ++i, ++j)
        assert(*i == m[j]);
}

int main()
{
    test();
}
