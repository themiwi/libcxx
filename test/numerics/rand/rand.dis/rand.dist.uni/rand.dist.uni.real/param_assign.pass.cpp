//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <random>

// template<class RealType = double>
// class uniform_real_distribution
// {
//     class param_type;

#include <random>
#include <limits>
#include <cassert>

int main()
{
    {
        typedef std::uniform_real_distribution<float> D;
        typedef D::param_type param_type;
        param_type p0(5, 10);
        param_type p;
        p = p0;
        assert(p.a() == 5);
        assert(p.b() == 10);
    }
}
