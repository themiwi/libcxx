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
// class negative_binomial_distribution
// {
//     class param_type;

#include <random>
#include <type_traits>

int main()
{
    {
        typedef std::negative_binomial_distribution<> D;
        typedef D::param_type param_type;
        typedef param_type::distribution_type distribution_type;
        static_assert((std::is_same<D, distribution_type>::value), "");
    }
}
