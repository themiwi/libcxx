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

// unordered_map(size_type n, const hasher& hf, const key_equal& eql, const allocator_type& a);

#include <unordered_map>
#include <cassert>

#include "../../../NotConstructible.h"
#include "../../../test_compare.h"
#include "../../../test_hash.h"
#include "../../../test_allocator.h"

int main()
{
    {
        typedef std::unordered_map<NotConstructible, NotConstructible,
                                   test_hash<std::hash<NotConstructible> >,
                                   test_compare<std::equal_to<NotConstructible> >,
                                   test_allocator<std::pair<const NotConstructible,
                                                                  NotConstructible> >
                                   > C;
        C c(7,
            test_hash<std::hash<NotConstructible> >(8),
            test_compare<std::equal_to<NotConstructible> >(9),
            test_allocator<std::pair<const NotConstructible, NotConstructible> >(10)
           );
        assert(c.bucket_count() == 7);
        assert(c.hash_function() == test_hash<std::hash<NotConstructible> >(8));
        assert(c.key_eq() == test_compare<std::equal_to<NotConstructible> >(9));
        assert(c.get_allocator() ==
               (test_allocator<std::pair<const NotConstructible, NotConstructible> >(10)));
        assert(c.size() == 0);
        assert(c.empty());
        assert(std::distance(c.begin(), c.end()) == 0);
        assert(c.load_factor() == 0);
        assert(c.max_load_factor() == 1);
    }
}
