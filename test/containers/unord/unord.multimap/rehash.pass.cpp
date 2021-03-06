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

// void rehash(size_type n);

#include <unordered_map>
#include <string>
#include <cassert>

void test(const std::unordered_multimap<int, std::string>& c)
{
    typedef std::unordered_multimap<int, std::string> C;
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
}

int main()
{
    {
        typedef std::unordered_multimap<int, std::string> C;
        typedef std::pair<int, std::string> P;
        P a[] =
        {
            P(1, "one"),
            P(2, "two"),
            P(3, "three"),
            P(4, "four"),
            P(1, "four"),
            P(2, "four"),
        };
        C c(a, a + sizeof(a)/sizeof(a[0]));
        test(c);
        assert(c.bucket_count() >= 7);
        c.rehash(3);
        assert(c.bucket_count() == 7);
        test(c);
        c.max_load_factor(2);
        c.rehash(3);
        assert(c.bucket_count() == 3);
        test(c);
        c.rehash(31);
        assert(c.bucket_count() == 31);
        test(c);
    }
}
