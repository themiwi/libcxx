//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <random>

// template<class _IntType = int>
// class uniform_int_distribution
// {
//     class param_type;

#include <random>
#include <limits>
#include <cassert>

int main()
{
    {
        typedef std::uniform_int_distribution<long> D;
        typedef D::param_type param_type;
        param_type p0(5, 10);
        param_type p = p0;
        assert(p.a() == 5);
        assert(p.b() == 10);
    }
}
