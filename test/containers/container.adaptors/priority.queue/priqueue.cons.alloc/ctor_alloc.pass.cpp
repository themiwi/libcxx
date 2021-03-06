//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <queue>

// template <class Alloc>
//     explicit priority_queue(const Alloc& a);

#include <queue>
#include <cassert>

#include "../../../test_allocator.h"

template <class T>
struct test
    : public std::priority_queue<T, std::vector<T, test_allocator<T> > >
{
    typedef std::priority_queue<T, std::vector<T, test_allocator<T> > > base;
    typedef typename base::container_type container_type;
    typedef typename base::value_compare value_compare;

    explicit test(const test_allocator<int>& a) : base(a) {}
    test(const value_compare& comp, const test_allocator<int>& a)
        : base(comp, c, a) {}
    test(const value_compare& comp, const container_type& c,
        const test_allocator<int>& a) : base(comp, c, a) {}
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    test(const value_compare& comp, container_type&& c,
         const test_allocator<int>& a) : base(comp, std::move(c), a) {}
    test(test&& q, const test_allocator<int>& a) : base(std::move(q), a) {}
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
    test_allocator<int> get_allocator() {return c.get_allocator();}

    using base::c;
};

int main()
{
    test<int> q((test_allocator<int>(3)));
    assert(q.c.get_allocator() == test_allocator<int>(3));
    assert(q.c.size() == 0);
}
