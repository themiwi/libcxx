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

//       iterator upper_bound(const key_type& k);
// const_iterator upper_bound(const key_type& k) const;

#include <set>
#include <cassert>

int main()
{
    typedef int V;
    typedef std::set<int> M;
    {
        typedef M::iterator R;
        V ar[] =
        {
            5,
            7,
            9,
            11,
            13,
            15,
            17,
            19
        };
        M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.upper_bound(5);
        assert(r == next(m.begin(), 1));
        r = m.upper_bound(7);
        assert(r == next(m.begin(), 2));
        r = m.upper_bound(9);
        assert(r == next(m.begin(), 3));
        r = m.upper_bound(11);
        assert(r == next(m.begin(), 4));
        r = m.upper_bound(13);
        assert(r == next(m.begin(), 5));
        r = m.upper_bound(15);
        assert(r == next(m.begin(), 6));
        r = m.upper_bound(17);
        assert(r == next(m.begin(), 7));
        r = m.upper_bound(19);
        assert(r == next(m.begin(), 8));
        r = m.upper_bound(4);
        assert(r == next(m.begin(), 0));
        r = m.upper_bound(6);
        assert(r == next(m.begin(), 1));
        r = m.upper_bound(8);
        assert(r == next(m.begin(), 2));
        r = m.upper_bound(10);
        assert(r == next(m.begin(), 3));
        r = m.upper_bound(12);
        assert(r == next(m.begin(), 4));
        r = m.upper_bound(14);
        assert(r == next(m.begin(), 5));
        r = m.upper_bound(16);
        assert(r == next(m.begin(), 6));
        r = m.upper_bound(18);
        assert(r == next(m.begin(), 7));
        r = m.upper_bound(20);
        assert(r == next(m.begin(), 8));
    }
    {
        typedef M::const_iterator R;
        V ar[] =
        {
            5,
            7,
            9,
            11,
            13,
            15,
            17,
            19
        };
        const M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.upper_bound(5);
        assert(r == next(m.begin(), 1));
        r = m.upper_bound(7);
        assert(r == next(m.begin(), 2));
        r = m.upper_bound(9);
        assert(r == next(m.begin(), 3));
        r = m.upper_bound(11);
        assert(r == next(m.begin(), 4));
        r = m.upper_bound(13);
        assert(r == next(m.begin(), 5));
        r = m.upper_bound(15);
        assert(r == next(m.begin(), 6));
        r = m.upper_bound(17);
        assert(r == next(m.begin(), 7));
        r = m.upper_bound(19);
        assert(r == next(m.begin(), 8));
        r = m.upper_bound(4);
        assert(r == next(m.begin(), 0));
        r = m.upper_bound(6);
        assert(r == next(m.begin(), 1));
        r = m.upper_bound(8);
        assert(r == next(m.begin(), 2));
        r = m.upper_bound(10);
        assert(r == next(m.begin(), 3));
        r = m.upper_bound(12);
        assert(r == next(m.begin(), 4));
        r = m.upper_bound(14);
        assert(r == next(m.begin(), 5));
        r = m.upper_bound(16);
        assert(r == next(m.begin(), 6));
        r = m.upper_bound(18);
        assert(r == next(m.begin(), 7));
        r = m.upper_bound(20);
        assert(r == next(m.begin(), 8));
    }
}
