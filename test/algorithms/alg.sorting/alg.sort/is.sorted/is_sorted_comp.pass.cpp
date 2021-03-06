//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator Iter, StrictWeakOrder<auto, Iter::value_type> Compare>
//   requires CopyConstructible<Compare>
//   bool
//   is_sorted(Iter first, Iter last, Compare comp);

#include <algorithm>
#include <functional>
#include <cassert>

#include "../../../iterators.h"

template <class Iter>
void
test()
{
    {
    int a[] = {0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a)));
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }

    {
    int a[] = {0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }

    {
    int a[] = {0, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {0, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }

    {
    int a[] = {0, 0, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {0, 0, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {0, 0, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {0, 0, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Iter(a), Iter(a+sa), std::greater<int>()));
    }
}

int main()
{
    test<forward_iterator<const int*> >();
    test<bidirectional_iterator<const int*> >();
    test<random_access_iterator<const int*> >();
    test<const int*>();
}
