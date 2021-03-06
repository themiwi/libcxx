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
//   assign(const charT* s, size_type n);

#include <string>
#include <stdexcept>
#include <cassert>

template <class S>
void
test(S s, const typename S::value_type* str, typename S::size_type n, S expected)
{
    s.assign(str, n);
    assert(s.__invariants());
    assert(s == expected);
}

int main()
{
    typedef std::string S;
    test(S(), "", 0, S());
    test(S(), "12345", 3, S("123"));
    test(S(), "12345", 4, S("1234"));
    test(S(), "12345678901234567890", 0, S());
    test(S(), "12345678901234567890", 1, S("1"));
    test(S(), "12345678901234567890", 3, S("123"));
    test(S(), "12345678901234567890", 20, S("12345678901234567890"));

    test(S("12345"), "", 0, S());
    test(S("12345"), "12345", 5, S("12345"));
    test(S("12345"), "1234567890", 10, S("1234567890"));

    test(S("12345678901234567890"), "", 0, S());
    test(S("12345678901234567890"), "12345", 5, S("12345"));
    test(S("12345678901234567890"), "12345678901234567890", 20,
         S("12345678901234567890"));
}
