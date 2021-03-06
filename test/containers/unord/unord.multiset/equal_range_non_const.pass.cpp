//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <unordered_set>

// template <class Value, class Hash = hash<Value>, class Pred = equal_to<Value>,
//           class Alloc = allocator<Value>>
// class unordered_multiset

// pair<iterator, iterator> equal_range(const key_type& k);

#include <unordered_set>
#include <cassert>

int main()
{
    {
        typedef std::unordered_multiset<int> C;
        typedef C::iterator I;
        typedef int P;
        P a[] =
        {
            P(10),
            P(20),
            P(30),
            P(40),
            P(50),
            P(50),
            P(50),
            P(60),
            P(70),
            P(80)
        };
        C c(std::begin(a), std::end(a));
        std::pair<I, I> r = c.equal_range(30);
        assert(std::distance(r.first, r.second) == 1);
        assert(*r.first == 30);
        r = c.equal_range(5);
        assert(std::distance(r.first, r.second) == 0);
        r = c.equal_range(50);
        assert(std::distance(r.first, r.second) == 3);
        assert(*r.first == 50);
        ++r.first;
        assert(*r.first == 50);
        ++r.first;
        assert(*r.first == 50);
    }
}
