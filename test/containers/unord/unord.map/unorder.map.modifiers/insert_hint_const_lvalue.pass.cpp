//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <unordered_map>

// template <class Key, class T, class Hash = hash<Key>, class Pred = equal_to<Key>,
//           class Alloc = allocator<pair<const Key, T>>>
// class unordered_map

// iterator insert(const_iterator p, const value_type& x);

#include <unordered_map>
#include <cassert>

int main()
{
    {
        typedef std::unordered_map<double, int> C;
        typedef C::iterator R;
        typedef C::value_type P;
        C c;
        C::const_iterator e = c.end();
        R r = c.insert(e, P(3.5, 3));
        assert(c.size() == 1);
        assert(r->first == 3.5);
        assert(r->second == 3);

        r = c.insert(e, P(3.5, 4));
        assert(c.size() == 1);
        assert(r->first == 3.5);
        assert(r->second == 3);

        r = c.insert(e, P(4.5, 4));
        assert(c.size() == 2);
        assert(r->first == 4.5);
        assert(r->second == 4);

        r = c.insert(e, P(5.5, 4));
        assert(c.size() == 3);
        assert(r->first == 5.5);
        assert(r->second == 4);
    }
}
