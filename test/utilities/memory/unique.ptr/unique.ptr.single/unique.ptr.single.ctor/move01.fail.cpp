//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// unique_ptr

// Test unique_ptr move ctor

#include <memory>
#include <cassert>

// test move ctor.  Can't copy from lvalue

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
    {
    std::unique_ptr<A> s(new A);
    A* p = s.get();
    std::unique_ptr<A> s2 = s;
    assert(s2.get() == p);
    assert(s.get() == 0);
    assert(A::count == 1);
    }
    assert(A::count == 0);
}
