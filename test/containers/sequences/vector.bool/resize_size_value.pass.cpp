//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <vector>
// vector<bool>

// void resize(size_type sz, const value_type& x);

#include <vector>
#include <cassert>

int main()
{
    {
        std::vector<bool> v(100);
        v.resize(50, 1);
        assert(v.size() == 50);
        assert(v.capacity() >= 100);
        assert(v == std::vector<bool>(50));
        v.resize(200, 1);
        assert(v.size() == 200);
        assert(v.capacity() >= 200);
        for (unsigned i = 0; i < 50; ++i)
            assert(v[i] == 0);
        for (unsigned i = 50; i < 200; ++i)
            assert(v[i] == 1);
    }
}
