//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <unordered_set>

// template <class Value, class Hash = hash<Value>, class Pred = equal_to<Value>,
//           class Alloc = allocator<Value>>
// class unordered_set

// float max_load_factor() const;
// void max_load_factor(float mlf);

#include <unordered_set>
#include <cassert>

int main()
{
    {
        typedef std::unordered_set<int> C;
        typedef int P;
        const C c;
        assert(c.max_load_factor() == 1);
    }
    {
        typedef std::unordered_set<int> C;
        typedef int P;
        C c;
        assert(c.max_load_factor() == 1);
        c.max_load_factor(2.5);
        assert(c.max_load_factor() == 2.5);
    }
}
