//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// shared_ptr(nullptr_t)

#include <memory>
#include <cassert>

int main()
{
    std::shared_ptr<int> p(nullptr);
    assert(p.use_count() == 0);
    assert(p.get() == 0);
}
