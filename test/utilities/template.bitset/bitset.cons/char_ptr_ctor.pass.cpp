//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// test bitset(const char *str);

#include <bitset>
#include <cassert>

template <std::size_t N>
void test_char_pointer_ctor()
{
    {
    try
    {
        std::bitset<N> v("xxx1010101010xxxx");
        assert(false);
    }
    catch (std::invalid_argument&)
    {
    }
    }

    {
    const char str[] ="1010101010";
    std::bitset<N> v(str);
    std::size_t M = std::min<std::size_t>(N, 10);
    for (std::size_t i = 0; i < M; ++i)
        assert(v[i] == (str[M - 1 - i] == '1'));
    for (std::size_t i = 10; i < N; ++i)
        assert(v[i] == false);
    }
}

int main()
{
    test_char_pointer_ctor<0>();
    test_char_pointer_ctor<1>();
    test_char_pointer_ctor<31>();
    test_char_pointer_ctor<32>();
    test_char_pointer_ctor<33>();
    test_char_pointer_ctor<63>();
    test_char_pointer_ctor<64>();
    test_char_pointer_ctor<65>();
    test_char_pointer_ctor<1000>();
}
