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
// class unordered_multimap

// unordered_multimap(initializer_list<value_type> il);

#include <unordered_map>
#include <string>
#include <cassert>

#include "../../../test_compare.h"
#include "../../../test_hash.h"
#include "../../../test_allocator.h"

int main()
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    {
        typedef std::unordered_multimap<int, std::string,
                                   test_hash<std::hash<int> >,
                                   test_compare<std::equal_to<int> >,
                                   test_allocator<std::pair<const int, std::string> >
                                   > C;
        typedef std::pair<int, std::string> P;
        C c = {
                P(1, "one"),
                P(2, "two"),
                P(3, "three"),
                P(4, "four"),
                P(1, "four"),
                P(2, "four"),
              };
        assert(c.bucket_count() >= 7);
        assert(c.size() == 6);
        typedef std::pair<C::const_iterator, C::const_iterator> Eq;
        Eq eq = c.equal_range(1);
        assert(std::distance(eq.first, eq.second) == 2);
        C::const_iterator i = eq.first;
        assert(i->first == 1);
        assert(i->second == "one");
        ++i;
        assert(i->first == 1);
        assert(i->second == "four");
        eq = c.equal_range(2);
        assert(std::distance(eq.first, eq.second) == 2);
        i = eq.first;
        assert(i->first == 2);
        assert(i->second == "two");
        ++i;
        assert(i->first == 2);
        assert(i->second == "four");

        eq = c.equal_range(3);
        assert(std::distance(eq.first, eq.second) == 1);
        i = eq.first;
        assert(i->first == 3);
        assert(i->second == "three");
        eq = c.equal_range(4);
        assert(std::distance(eq.first, eq.second) == 1);
        i = eq.first;
        assert(i->first == 4);
        assert(i->second == "four");
        assert(std::distance(c.begin(), c.end()) == c.size());
        assert(std::distance(c.cbegin(), c.cend()) == c.size());
        assert(c.load_factor() == (float)c.size()/c.bucket_count());
        assert(c.max_load_factor() == 1);
        assert(c.hash_function() == test_hash<std::hash<int> >());
        assert(c.key_eq() == test_compare<std::equal_to<int> >());
        assert((c.get_allocator() == test_allocator<std::pair<const int, std::string> >()));
    }
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
