//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// size_type find(charT c, size_type pos = 0) const;

#include <string>
#include <cassert>

template <class S>
void
test(const S& s, typename S::value_type c, typename S::size_type pos,
     typename S::size_type x)
{
    assert(s.find(c, pos) == x);
    if (x != S::npos)
        assert(pos <= x && x + 1 <= s.size());
}

template <class S>
void
test(const S& s, typename S::value_type c, typename S::size_type x)
{
    assert(s.find(c) == x);
    if (x != S::npos)
        assert(0 <= x && x + 1 <= s.size());
}

typedef std::string S;

int main()
{
    test(S(""), 'c', 0, S::npos);
    test(S(""), 'c', 1, S::npos);
    test(S("abcde"), 'c', 0, 2);
    test(S("abcde"), 'c', 1, 2);
    test(S("abcde"), 'c', 2, 2);
    test(S("abcde"), 'c', 4, S::npos);
    test(S("abcde"), 'c', 5, S::npos);
    test(S("abcde"), 'c', 6, S::npos);
    test(S("abcdeabcde"), 'c', 0, 2);
    test(S("abcdeabcde"), 'c', 1, 2);
    test(S("abcdeabcde"), 'c', 5, 7);
    test(S("abcdeabcde"), 'c', 9, S::npos);
    test(S("abcdeabcde"), 'c', 10, S::npos);
    test(S("abcdeabcde"), 'c', 11, S::npos);
    test(S("abcdeabcdeabcdeabcde"), 'c', 0, 2);
    test(S("abcdeabcdeabcdeabcde"), 'c', 1, 2);
    test(S("abcdeabcdeabcdeabcde"), 'c', 10, 12);
    test(S("abcdeabcdeabcdeabcde"), 'c', 19, S::npos);
    test(S("abcdeabcdeabcdeabcde"), 'c', 20, S::npos);
    test(S("abcdeabcdeabcdeabcde"), 'c', 21, S::npos);

    test(S(""), 'c', S::npos);
    test(S("abcde"), 'c', 2);
    test(S("abcdeabcde"), 'c', 2);
    test(S("abcdeabcdeabcdeabcde"), 'c', 2);
}
