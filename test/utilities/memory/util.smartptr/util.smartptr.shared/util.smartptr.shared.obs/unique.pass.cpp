//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// shared_ptr

// bool unique() const;

#include <memory>
#include <cassert>

int main()
{
    const std::shared_ptr<int> p(new int(32));
    assert(p.unique());
    {
    std::shared_ptr<int> p2 = p;
    assert(!p.unique());
    }
    assert(p.unique());
}
