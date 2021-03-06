//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// basic_string<charT,traits,Allocator>&
//   append(size_type n, charT c);

#include <string>
#include <cassert>

template <class S>
void
test(S s, typename S::size_type n, typename S::value_type c, S expected)
{
    s.append(n, c);
    assert(s.__invariants());
    assert(s == expected);
}

int main()
{
    typedef std::string S;
    test(S(), 0, 'a', S());
    test(S(), 1, 'a', S(1, 'a'));
    test(S(), 10, 'a', S(10, 'a'));
    test(S(), 100, 'a', S(100, 'a'));

    test(S("12345"), 0, 'a', S("12345"));
    test(S("12345"), 1, 'a', S("12345a"));
    test(S("12345"), 10, 'a', S("12345aaaaaaaaaa"));

    test(S("12345678901234567890"), 0, 'a', S("12345678901234567890"));
    test(S("12345678901234567890"), 1, 'a', S("12345678901234567890a"));
    test(S("12345678901234567890"), 10, 'a', S("12345678901234567890aaaaaaaaaa"));
}
