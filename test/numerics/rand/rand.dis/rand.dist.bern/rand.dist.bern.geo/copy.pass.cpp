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

// geometric_distribution(const geometric_distribution&);

#include <random>
#include <cassert>

void
test1()
{
    typedef std::geometric_distribution<> D;
    D d1(0.75);
    D d2 = d1;
    assert(d1 == d2);
}

int main()
{
    test1();
}
