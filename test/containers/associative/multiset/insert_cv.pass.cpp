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

// iterator insert(const value_type& v);

#include <set>
#include <cassert>

int main()
{
    {
        typedef std::multiset<int> M;
        typedef M::iterator R;
        M m;
        R r = m.insert(M::value_type(2));
        assert(r == m.begin());
        assert(m.size() == 1);
        assert(*r == 2);

        r = m.insert(M::value_type(1));
        assert(r == m.begin());
        assert(m.size() == 2);
        assert(*r == 1);

        r = m.insert(M::value_type(3));
        assert(r == prev(m.end()));
        assert(m.size() == 3);
        assert(*r == 3);

        r = m.insert(M::value_type(3));
        assert(r == prev(m.end()));
        assert(m.size() == 4);
        assert(*r == 3);
    }
}
