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

// result_type min() const;

#include <random>
#include <cassert>

int main()
{
    {
        typedef std::gamma_distribution<> D;
        D d(.5, .5);
        assert(d.min() == 0);
    }
}
