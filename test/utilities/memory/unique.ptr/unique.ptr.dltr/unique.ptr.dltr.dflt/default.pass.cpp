//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// default_delete

#include <memory>
#include <cassert>

struct A
{
    static int count;
    A() {++count;}
    A(const A&) {++count;}
    ~A() {--count;}
};

int A::count = 0;

int main()
{
    std::default_delete<A> d;
    A* p = new A;
    assert(A::count == 1);
    d(p);
    assert(A::count == 0);
}
