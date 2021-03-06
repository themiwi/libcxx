//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// allocator:
// size_type max_size() const throw();

#include <memory>
#include <limits>
#include <cstddef>
#include <cassert>

int new_called = 0;

int main()
{
    const std::allocator<int> a;
    std::size_t M = a.max_size() * sizeof(int);
    assert(M > 0xFFFF && M <= std::numeric_limits<std::size_t>::max());
}
