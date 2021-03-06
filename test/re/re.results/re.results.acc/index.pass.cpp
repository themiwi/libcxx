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

// const_reference operator[](size_type n) const;

#include <regex>
#include <cassert>

void
test()
{
    std::match_results<const char*> m;
    const char s[] = "abcdefghijk";
    assert(std::regex_search(s, m, std::regex("cd((e)fg)hi")));

    assert(m[0].first == s+2);
    assert(m[0].second == s+9);
    assert(m[0].matched == true);

    assert(m[1].first == s+4);
    assert(m[1].second == s+7);
    assert(m[1].matched == true);

    assert(m[2].first == s+4);
    assert(m[2].second == s+5);
    assert(m[2].matched == true);

    assert(m[3].first == s+11);
    assert(m[3].second == s+11);
    assert(m[3].matched == false);

    assert(m[4].first == s+11);
    assert(m[4].second == s+11);
    assert(m[4].matched == false);
}

int main()
{
    test();
}
