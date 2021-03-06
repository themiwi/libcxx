//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <iterator>

// move_iterator

// template <class U>
//   requires HasConstructor<Iter, const U&>
//   move_iterator(const move_iterator<U> &u);

#include <iterator>
#include <cassert>

#include "../../../../iterators.h"

template <class It, class U>
void
test(U u)
{
    const std::move_iterator<U> r2(u);
    std::move_iterator<It> r1 = r2;
    assert(r1.base() == u);
}

struct base {};
struct derived : base {};

int main()
{
    derived d;

    test<input_iterator<base*> >(input_iterator<derived*>(&d));
    test<forward_iterator<base*> >(forward_iterator<derived*>(&d));
    test<bidirectional_iterator<base*> >(bidirectional_iterator<derived*>(&d));
    test<random_access_iterator<const base*> >(random_access_iterator<derived*>(&d));
    test<base*>(&d);
}
