//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <list>

// template <class Compare> sort(Compare comp);

#include <list>
#include <functional>
#include <cassert>

int main()
{
    int a1[] = {4, 8, 1, 0, 5, 7, 2, 3, 6, 11, 10, 9};
    int a2[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::list<int> c1(a1, a1+sizeof(a1)/sizeof(a1[0]));
    c1.sort(std::greater<int>());
    assert(c1 == std::list<int>(a2, a2+sizeof(a2)/sizeof(a2[0])));
}
