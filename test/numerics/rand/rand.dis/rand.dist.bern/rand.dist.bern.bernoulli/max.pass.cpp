//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <random>

// class bernoulli_distribution

// result_type max() const;

#include <random>
#include <cassert>

int main()
{
    {
        typedef std::bernoulli_distribution D;
        D d(.25);
        assert(d.max() == true);
    }
}
