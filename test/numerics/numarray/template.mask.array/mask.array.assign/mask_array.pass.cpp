//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <valarray>

// template <class T> class mask_array

// void mask_array& operator=(const mask_array& ma) const;

#include <valarray>
#include <cassert>

int main()
{
    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    const std::size_t N1 = sizeof(a1)/sizeof(a1[0]);
    bool b1[N1] = {true,  false, false, true,  true,  false,
                   false, true,  false, false, false, true};
    int a2[] = {-1, -2, -3, -4, -5, -6, -7, -8};
    const std::size_t N2 = sizeof(a2)/sizeof(a2[0]);
    bool b2[N2] = {true,  false, true, true,
                   false, false, true, true};
    std::valarray<int> v1(a1, N1);
    const std::valarray<int> v2(a2, N2);
    std::valarray<bool> vb1(b1, N1);
    std::valarray<bool> vb2(b2, N2);
    v1[vb1] = v2[vb2];
    assert(v1.size() == 16);
    assert(v1[ 0] == -1);
    assert(v1[ 1] ==  1);
    assert(v1[ 2] ==  2);
    assert(v1[ 3] == -3);
    assert(v1[ 4] == -4);
    assert(v1[ 5] ==  5);
    assert(v1[ 6] ==  6);
    assert(v1[ 7] == -7);
    assert(v1[ 8] ==  8);
    assert(v1[ 9] ==  9);
    assert(v1[10] == 10);
    assert(v1[11] == -8);
    assert(v1[12] == 12);
    assert(v1[13] == 13);
    assert(v1[14] == 14);
    assert(v1[15] == 15);
}
