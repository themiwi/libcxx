//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class multiset

// template <class InputIterator>
//     multiset(InputIterator first, InputIterator last,
//         const value_compare& comp, const allocator_type& a);

#include <set>
#include <cassert>

#include "../../../iterators.h"
#include "../../../test_compare.h"
#include "../../../test_allocator.h"

int main()
{
    typedef int V;
    V ar[] =
    {
        1,
        1,
        1,
        2,
        2,
        2,
        3,
        3,
        3
    };
    typedef test_compare<std::less<V> > C;
    typedef test_allocator<V> A;
    std::multiset<V, C, A> m(input_iterator<const V*>(ar),
                        input_iterator<const V*>(ar+sizeof(ar)/sizeof(ar[0])),
                        C(5), A(7));
    assert(m.value_comp() == C(5));
    assert(m.get_allocator() == A(7));
    assert(m.size() == 9);
    assert(distance(m.begin(), m.end()) == 9);
    assert(*next(m.begin(), 0) == 1);
    assert(*next(m.begin(), 1) == 1);
    assert(*next(m.begin(), 2) == 1);
    assert(*next(m.begin(), 3) == 2);
    assert(*next(m.begin(), 4) == 2);
    assert(*next(m.begin(), 5) == 2);
    assert(*next(m.begin(), 6) == 3);
    assert(*next(m.begin(), 7) == 3);
    assert(*next(m.begin(), 8) == 3);
}
