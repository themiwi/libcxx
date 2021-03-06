//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <iterator>

// insert_iterator

// insert_iterator(Cont& x, Cont::iterator i);

#include <iterator>
#include <vector>

template <class C>
void
test(C c)
{
    std::insert_iterator<C> i(c, c.begin());
}

int main()
{
    test(std::vector<int>());
}
