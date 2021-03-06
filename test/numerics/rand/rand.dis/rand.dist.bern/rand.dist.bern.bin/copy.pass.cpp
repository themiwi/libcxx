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
// class binomial_distribution

// binomial_distribution(const binomial_distribution&);

#include <random>
#include <cassert>

void
test1()
{
    typedef std::binomial_distribution<> D;
    D d1(2, 0.75);
    D d2 = d1;
    assert(d1 == d2);
}

int main()
{
    test1();
}
