//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// unique_ptr

// test op*()

#include <memory>
#include <cassert>

int main()
{
    {
    std::unique_ptr<int[]> p(new int [3]);
    if (p)
        ;
    else
        assert(false);
    if (!p)
        assert(false);
    }
    {
    std::unique_ptr<int[]> p;
    if (!p)
        ;
    else
        assert(false);
    if (p)
        assert(false);
    }
}
