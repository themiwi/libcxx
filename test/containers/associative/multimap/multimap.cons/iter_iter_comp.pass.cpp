//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// class multimap

// template <class InputIterator>
//     multimap(InputIterator first, InputIterator last,
//              const key_compare& comp);

#include <map>
#include <cassert>

#include "../../../test_compare.h"

int main()
{
    typedef std::pair<const int, double> V;
    V ar[] =
    {
        V(1, 1),
        V(1, 1.5),
        V(1, 2),
        V(2, 1),
        V(2, 1.5),
        V(2, 2),
        V(3, 1),
        V(3, 1.5),
        V(3, 2),
    };
    typedef test_compare<std::less<int> > C;
    std::multimap<int, double, C> m(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5));
    assert(m.key_comp() == C(5));
    assert(m.size() == 9);
    assert(distance(m.begin(), m.end()) == 9);
    assert(*m.begin() == V(1, 1));
    assert(*next(m.begin()) == V(1, 1.5));
    assert(*next(m.begin(), 2) == V(1, 2));
    assert(*next(m.begin(), 3) == V(2, 1));
    assert(*next(m.begin(), 4) == V(2, 1.5));
    assert(*next(m.begin(), 5) == V(2, 2));
    assert(*next(m.begin(), 6) == V(3, 1));
    assert(*next(m.begin(), 7) == V(3, 1.5));
    assert(*next(m.begin(), 8) == V(3, 2));
}
