//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <functional>

// class function<R(ArgTypes...)>

// template<class F, class A> function(allocator_arg_t, const A&, F);

#include <functional>
#include <cassert>

#include "../test_allocator.h"

class A
{
    int data_[10];
public:
    static int count;

    A()
    {
        ++count;
        for (int i = 0; i < 10; ++i)
            data_[i] = i;
    }

    A(const A&) {++count;}

    ~A() {--count;}

    int operator()(int i) const
    {
        for (int j = 0; j < 10; ++j)
            i += data_[j];
        return i;
    }

    int foo(int) const {return 1;}
};

int A::count = 0;

int g(int) {return 0;}

int main()
{
    {
    std::function<int(int)> f(std::allocator_arg, test_allocator<A>(), A());
    assert(A::count == 1);
    assert(f.target<A>());
    assert(f.target<int(*)(int)>() == 0);
    }
    assert(A::count == 0);
    {
    std::function<int(int)> f(std::allocator_arg, test_allocator<int(*)(int)>(), g);
    assert(f.target<int(*)(int)>());
    assert(f.target<A>() == 0);
    }
    {
    std::function<int(int)> f(std::allocator_arg, test_allocator<int(*)(int)>(),
                              (int (*)(int))0);
    assert(!f);
    assert(f.target<int(*)(int)>() == 0);
    assert(f.target<A>() == 0);
    }
    {
    std::function<int(const A*, int)> f(std::allocator_arg,
                                        test_allocator<int(A::*)(int)const>(),
                                        &A::foo);
    assert(f);
    assert(f.target<int (A::*)(int) const>() != 0);
    }
}
