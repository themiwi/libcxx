//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <list>

// void resize(size_type sz, const value_type& x);

#include <list>
#include <cassert>
#include "../../../DefaultOnly.h"

int main()
{
    {
        std::list<double> l(5, 2);
        l.resize(2, 3.5);
        assert(l.size() == 2);
        assert(std::distance(l.begin(), l.end()) == 2);
        assert(l == std::list<double>(2, 2));
    }
    {
        std::list<double> l(5, 2);
        l.resize(10, 3.5);
        assert(l.size() == 10);
        assert(std::distance(l.begin(), l.end()) == 10);
        assert(l.front() == 2);
        assert(l.back() == 3.5);
    }
}
