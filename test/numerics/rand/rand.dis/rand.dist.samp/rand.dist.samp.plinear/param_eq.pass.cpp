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
// class piecewise_linear_distribution
// {
//     class param_type;

#include <random>
#include <limits>
#include <cassert>

int main()
{
    {
        typedef std::piecewise_linear_distribution<> D;
        typedef D::param_type P;
        double b[] = {10, 14, 16, 17};
        double p[] = {25, 62.5, 12.5, 0};
        P p1(b, b+4, p);
        P p2(b, b+4, p);
        assert(p1 == p2);
    }
    {
        typedef std::piecewise_linear_distribution<> D;
        typedef D::param_type P;
        double b[] = {10, 14, 16, 17};
        double p[] = {25, 62.5, 12.5, 0};
        P p1(b, b+3, p);
        P p2(b, b+4, p);
        assert(p1 != p2);
    }
}
