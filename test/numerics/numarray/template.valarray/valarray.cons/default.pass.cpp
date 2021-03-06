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

// valarray();

#include <valarray>
#include <cassert>

int main()
{
    {
        std::valarray<int> v;
        assert(v.size() == 0);
    }
    {
        std::valarray<float> v;
        assert(v.size() == 0);
    }
    {
        std::valarray<double> v;
        assert(v.size() == 0);
    }
    {
        std::valarray<std::valarray<double> > v;
        assert(v.size() == 0);
    }
}
