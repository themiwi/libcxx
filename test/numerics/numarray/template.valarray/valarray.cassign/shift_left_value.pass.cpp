//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <valarray>

// template<class T> class valarray;

// valarray& operator<<=(const value_type& x);

#include <valarray>
#include <cassert>

int main()
{
    {
        typedef int T;
        T a1[] = { 1,   2,  3,  4,  5};
        T a2[] = { 8,  16, 24, 32, 40};
        const unsigned N = sizeof(a1)/sizeof(a1[0]);
        std::valarray<T> v1(a1, N);
        std::valarray<T> v2(a2, N);
        v1 <<= 3;
        assert(v1.size() == v2.size());
        for (int i = 0; i < v1.size(); ++i)
            assert(v1[i] == v2[i]);
    }
}
