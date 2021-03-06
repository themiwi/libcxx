//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <vector>

// void resize(size_type sz, const value_type& x);

#include <vector>
#include <cassert>
#include "../../../stack_allocator.h"

int main()
{
    {
        std::vector<int> v(100);
        v.resize(50, 1);
        assert(v.size() == 50);
        assert(v.capacity() == 100);
        assert(v == std::vector<int>(50));
        v.resize(200, 1);
        assert(v.size() == 200);
        assert(v.capacity() >= 200);
        for (unsigned i = 0; i < 50; ++i)
            assert(v[i] == 0);
        for (unsigned i = 50; i < 200; ++i)
            assert(v[i] == 1);
    }
    {
        std::vector<int, stack_allocator<int, 300> > v(100);
        v.resize(50, 1);
        assert(v.size() == 50);
        assert(v.capacity() == 100);
        v.resize(200, 1);
        assert(v.size() == 200);
        assert(v.capacity() >= 200);
    }
}
