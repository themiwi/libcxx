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

// Test unique_ptr(pointer, deleter) ctor

#include <memory>
#include <cassert>

// unique_ptr(pointer, deleter) should work with derived pointers

struct A
{
    static int count;
    A() {++count;}
    A(const A&) {++count;}
    virtual ~A() {--count;}
};

int A::count = 0;

struct B
    : public A
{
    static int count;
    B() {++count;}
    B(const B&) {++count;}
    virtual ~B() {--count;}
};

int B::count = 0;

class Deleter
{
    int state_;

public:
    Deleter() : state_(5) {}

    int state() const {return state_;}

    void operator()(A* p) {delete p;}
};

int main()
{
    {
    B* p = new B;
    assert(A::count == 1);
    assert(B::count == 1);
    std::unique_ptr<A, Deleter> s(p, Deleter());
    assert(s.get() == p);
    assert(s.get_deleter().state() == 5);
    }
    assert(A::count == 0);
    assert(B::count == 0);
}
