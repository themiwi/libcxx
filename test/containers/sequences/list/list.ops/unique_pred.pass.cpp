//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <list>

// template <class BinaryPred> void unique(BinaryPred pred);

#include <list>
#include <cassert>

bool g(int x, int y)
{
    return x == y;
}

int main()
{
    int a1[] = {2, 1, 1, 4, 4, 4, 4, 3, 3};
    int a2[] = {2, 1, 4, 3};
    std::list<int> c(a1, a1+sizeof(a1)/sizeof(a1[0]));
    c.unique(g);
    assert(c == std::list<int>(a2, a2+4));
}
