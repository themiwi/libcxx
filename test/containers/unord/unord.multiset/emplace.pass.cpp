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
// class unordered_multiset

// template <class... Args>
//     iterator emplace(Args&&... args);

#include <unordered_set>
#include <cassert>

#include "../../Emplaceable.h"

int main()
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    {
        typedef std::unordered_multiset<Emplaceable> C;
        typedef C::iterator R;
        C c;
        R r = c.emplace();
        assert(c.size() == 1);
        assert(*r == Emplaceable());

        r = c.emplace(Emplaceable(5, 6));
        assert(c.size() == 2);
        assert(*r == Emplaceable(5, 6));

        r = c.emplace(5, 6);
        assert(c.size() == 3);
        assert(*r == Emplaceable(5, 6));
    }
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
