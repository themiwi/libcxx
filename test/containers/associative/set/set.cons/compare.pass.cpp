//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class set

// explicit set(const value_compare& comp);

#include <set>
#include <cassert>

#include "../../../test_compare.h"

int main()
{
    typedef test_compare<std::less<int> > C;
    std::set<int, C> m(C(3));
    assert(m.empty());
    assert(m.begin() == m.end());
    assert(m.key_comp() == C(3));
}
