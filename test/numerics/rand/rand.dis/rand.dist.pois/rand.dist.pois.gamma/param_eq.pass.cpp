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
// class gamma_distribution
// {
//     class param_type;

#include <random>
#include <limits>
#include <cassert>

int main()
{
    {
        typedef std::gamma_distribution<> D;
        typedef D::param_type param_type;
        param_type p1(0.75, .5);
        param_type p2(0.75, .5);
        assert(p1 == p2);
    }
    {
        typedef std::gamma_distribution<> D;
        typedef D::param_type param_type;
        param_type p1(0.75, .5);
        param_type p2(0.5, .5);
        assert(p1 != p2);
    }
}
