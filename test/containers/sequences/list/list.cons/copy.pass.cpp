//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <list>

// list(const list& c);

#include <list>
#include <cassert>
#include "../../../DefaultOnly.h"
#include "../../../test_allocator.h"

int main()
{
    {
        std::list<int> l(3, 2);
        std::list<int> l2 = l;
        assert(l2 == l);
    }
    {
        std::list<int, test_allocator<int> > l(3, 2, test_allocator<int>(5));
        std::list<int, test_allocator<int> > l2 = l;
        assert(l2 == l);
        assert(l2.get_allocator() == l.get_allocator());
    }
#ifndef _LIBCPP_HAS_NO_ADVANCED_SFINAE
    {
        std::list<int, other_allocator<int> > l(3, 2, other_allocator<int>(5));
        std::list<int, other_allocator<int> > l2 = l;
        assert(l2 == l);
        assert(l2.get_allocator() == other_allocator<int>(-2));
    }
#endif  // _LIBCPP_HAS_NO_ADVANCED_SFINAE
}
