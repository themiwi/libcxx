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
//   bool operator!=(const basic_string<charT,traits,Allocator>& lhs,
//                   const basic_string<charT,traits,Allocator>& rhs);

#include <string>
#include <cassert>

template <class S>
void
test(const S& lhs, const S& rhs, bool x)
{
    assert((lhs != rhs) == x);
}

typedef std::string S;

int main()
{
    test(S(""), S(""), false);
    test(S(""), S("abcde"), true);
    test(S(""), S("abcdefghij"), true);
    test(S(""), S("abcdefghijklmnopqrst"), true);
    test(S("abcde"), S(""), true);
    test(S("abcde"), S("abcde"), false);
    test(S("abcde"), S("abcdefghij"), true);
    test(S("abcde"), S("abcdefghijklmnopqrst"), true);
    test(S("abcdefghij"), S(""), true);
    test(S("abcdefghij"), S("abcde"), true);
    test(S("abcdefghij"), S("abcdefghij"), false);
    test(S("abcdefghij"), S("abcdefghijklmnopqrst"), true);
    test(S("abcdefghijklmnopqrst"), S(""), true);
    test(S("abcdefghijklmnopqrst"), S("abcde"), true);
    test(S("abcdefghijklmnopqrst"), S("abcdefghij"), true);
    test(S("abcdefghijklmnopqrst"), S("abcdefghijklmnopqrst"), false);
}
