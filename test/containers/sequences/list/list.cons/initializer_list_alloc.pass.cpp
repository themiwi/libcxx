//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <list>

// list(initializer_list<value_type> il, const Allocator& a = allocator_type());

#include <list>
#include <cassert>

#include "../../../test_allocator.h"

int main()
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    std::list<int, test_allocator<int>> d({3, 4, 5, 6}, test_allocator<int>(3));
    assert(d.get_allocator() == test_allocator<int>(3));
    assert(d.size() == 4);
    std::list<int>::iterator i = d.begin();
    assert(*i++ == 3);
    assert(*i++ == 4);
    assert(*i++ == 5);
    assert(*i++ == 6);
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
