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

// multimap& operator=(const multimap& m);

#include <map>
#include <cassert>

#include "../../../test_compare.h"
#include "../../../test_allocator.h"

int main()
{
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
        typedef test_allocator<V> A;
        std::multimap<int, double, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(2));
        std::multimap<int, double, C, A> m(ar, ar+sizeof(ar)/sizeof(ar[0])/2, C(3), A(7));
        m = mo;
        assert(m == mo);
        assert(m.get_allocator() == A(7));
        assert(m.key_comp() == C(5));

        assert(mo.get_allocator() == A(2));
        assert(mo.key_comp() == C(5));
    }
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
        typedef other_allocator<V> A;
        std::multimap<int, double, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(2));
        std::multimap<int, double, C, A> m(ar, ar+sizeof(ar)/sizeof(ar[0])/2, C(3), A(7));
        m = mo;
        assert(m == mo);
        assert(m.get_allocator() == A(2));
        assert(m.key_comp() == C(5));

        assert(mo.get_allocator() == A(2));
        assert(mo.key_comp() == C(5));
    }
}
