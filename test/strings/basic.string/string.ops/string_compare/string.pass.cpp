//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// int compare(const basic_string& str) const

#include <string>
#include <cassert>

int sign(int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return -1;
    return 1;
}

template <class S>
void
test(const S& s, const S& str, int x)
{
    assert(sign(s.compare(str)) == sign(x));
}

typedef std::string S;

int main()
{
    test(S(""), S(""), 0);
    test(S(""), S("abcde"), -5);
    test(S(""), S("abcdefghij"), -10);
    test(S(""), S("abcdefghijklmnopqrst"), -20);
    test(S("abcde"), S(""), 5);
    test(S("abcde"), S("abcde"), 0);
    test(S("abcde"), S("abcdefghij"), -5);
    test(S("abcde"), S("abcdefghijklmnopqrst"), -15);
    test(S("abcdefghij"), S(""), 10);
    test(S("abcdefghij"), S("abcde"), 5);
    test(S("abcdefghij"), S("abcdefghij"), 0);
    test(S("abcdefghij"), S("abcdefghijklmnopqrst"), -10);
    test(S("abcdefghijklmnopqrst"), S(""), 20);
    test(S("abcdefghijklmnopqrst"), S("abcde"), 15);
    test(S("abcdefghijklmnopqrst"), S("abcdefghij"), 10);
    test(S("abcdefghijklmnopqrst"), S("abcdefghijklmnopqrst"), 0);
}
