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

// template<class T> void swap(weak_ptr<T>& a, weak_ptr<T>& b)

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
    {
        A* ptr1 = new A;
        A* ptr2 = new A;
        std::shared_ptr<A> p1(ptr1);
        std::weak_ptr<A> w1(p1);
        {
            std::shared_ptr<A> p2(ptr2);
            std::weak_ptr<A> w2(p2);
            swap(w1, w2);
            assert(w1.use_count() == 1);
            assert(w1.lock().get() == ptr2);
            assert(w2.use_count() == 1);
            assert(w2.lock().get() == ptr1);
            assert(A::count == 2);
        }
    }
    assert(A::count == 0);
}
