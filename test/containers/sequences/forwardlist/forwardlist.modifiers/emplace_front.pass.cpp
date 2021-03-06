//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <forward_list>

// template <class... Args> void emplace_front(Args&&... args);

#include <forward_list>
#include <cassert>

#include "../../../Emplaceable.h"

int main()
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    {
        typedef Emplaceable T;
        typedef std::forward_list<T> C;
        C c;
        c.emplace_front();
        assert(c.front() == Emplaceable());
        assert(distance(c.begin(), c.end()) == 1);
        c.emplace_front(1, 2.5);
        assert(c.front() == Emplaceable(1, 2.5));
        assert(*next(c.begin()) == Emplaceable());
        assert(distance(c.begin(), c.end()) == 2);
    }
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
