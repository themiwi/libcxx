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

// void swap(vector& x);

#include <vector>
#include <cassert>
#include "../../test_allocator.h"

int main()
{
    {
        std::vector<bool> v1(100);
        std::vector<bool> v2(200);
        v1.swap(v2);
        assert(v1.size() == 200);
        assert(v1.capacity() >= 200);
        assert(v2.size() == 100);
        assert(v2.capacity() >= 100);
    }
    {
        typedef test_allocator<bool> A;
        std::vector<bool, A> v1(100, true, A(1));
        std::vector<bool, A> v2(200, false, A(2));
        swap(v1, v2);
        assert(v1.size() == 200);
        assert(v1.capacity() >= 200);
        assert(v2.size() == 100);
        assert(v2.capacity() >= 100);
        assert(v1.get_allocator() == A(1));
        assert(v2.get_allocator() == A(2));
    }
    {
        typedef other_allocator<bool> A;
        std::vector<bool, A> v1(100, true, A(1));
        std::vector<bool, A> v2(200, false, A(2));
        swap(v1, v2);
        assert(v1.size() == 200);
        assert(v1.capacity() >= 200);
        assert(v2.size() == 100);
        assert(v2.capacity() >= 100);
        assert(v1.get_allocator() == A(2));
        assert(v2.get_allocator() == A(1));
    }
}
