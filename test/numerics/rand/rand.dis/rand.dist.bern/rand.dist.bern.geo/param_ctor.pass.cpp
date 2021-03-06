//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <random>

// template<class IntType = int>
// class geometric_distribution
// {
//     class param_type;

#include <random>
#include <limits>
#include <cassert>

int main()
{
    {
        typedef std::geometric_distribution<> D;
        typedef D::param_type param_type;
        param_type p;
        assert(p.p() == 0.5);
    }
    {
        typedef std::geometric_distribution<> D;
        typedef D::param_type param_type;
        param_type p(0.25);
        assert(p.p() == 0.25);
    }
}
