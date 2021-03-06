//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// template<class charT, class traits, class Allocator>
//   bool operator>(const charT* lhs, const basic_string<charT,traits,Allocator>& rhs);

#include <string>
#include <cassert>

template <class S>
void
test(const typename S::value_type* lhs, const S& rhs, bool x)
{
    assert((lhs > rhs) == x);
}

typedef std::string S;

int main()
{
    test("", S(""), false);
    test("", S("abcde"), false);
    test("", S("abcdefghij"), false);
    test("", S("abcdefghijklmnopqrst"), false);
    test("abcde", S(""), true);
    test("abcde", S("abcde"), false);
    test("abcde", S("abcdefghij"), false);
    test("abcde", S("abcdefghijklmnopqrst"), false);
    test("abcdefghij", S(""), true);
    test("abcdefghij", S("abcde"), true);
    test("abcdefghij", S("abcdefghij"), false);
    test("abcdefghij", S("abcdefghijklmnopqrst"), false);
    test("abcdefghijklmnopqrst", S(""), true);
    test("abcdefghijklmnopqrst", S("abcde"), true);
    test("abcdefghijklmnopqrst", S("abcdefghij"), true);
    test("abcdefghijklmnopqrst", S("abcdefghijklmnopqrst"), false);
}
