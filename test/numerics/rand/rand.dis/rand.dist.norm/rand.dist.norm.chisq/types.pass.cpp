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
// class chi_squared_distribution
// {
// public:
//     // types
//     typedef RealType result_type;

#include <random>
#include <type_traits>

int main()
{
    {
        typedef std::chi_squared_distribution<> D;
        typedef D::result_type result_type;
        static_assert((std::is_same<result_type, double>::value), "");
    }
    {
        typedef std::chi_squared_distribution<float> D;
        typedef D::result_type result_type;
        static_assert((std::is_same<result_type, float>::value), "");
    }
}
