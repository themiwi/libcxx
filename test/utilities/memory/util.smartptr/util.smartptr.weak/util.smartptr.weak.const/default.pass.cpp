//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// template<class T> class weak_ptr

// weak_ptr();

#include <memory>
#include <cassert>

struct A;

int main()
{
    std::weak_ptr<A> p;
    assert(p.use_count() == 0);
}
