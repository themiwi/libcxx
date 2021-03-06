//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// weak_ptr

// template<class U> bool owner_before(const weak_ptr<U>& b);

#include <memory>
#include <cassert>

int main()
{
    const std::shared_ptr<int> p1(new int);
    const std::shared_ptr<int> p2 = p1;
    const std::shared_ptr<int> p3(new int);
    const std::weak_ptr<int> w1(p1);
    const std::weak_ptr<int> w2(p2);
    const std::weak_ptr<int> w3(p3);
    assert(!w1.owner_before(w2));
    assert(!w2.owner_before(w1));
    assert(w1.owner_before(w3) || w3.owner_before(w1));
    assert(w3.owner_before(w1) == w3.owner_before(w2));
}
