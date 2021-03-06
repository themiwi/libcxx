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

// unique_ptr(nullptr_t);

#include <memory>
#include <cassert>

// default unique_ptr ctor should only require default Deleter ctor
class Deleter
{
    int state_;

    Deleter(Deleter&);
    Deleter& operator=(Deleter&);

public:
    Deleter() : state_(5) {}

    int state() const {return state_;}

    void operator()(void*) {}
};

int main()
{
    {
    std::unique_ptr<int[]> p(nullptr);
    assert(p.get() == 0);
    }
    {
    std::unique_ptr<int[], Deleter> p(nullptr);
    assert(p.get() == 0);
    assert(p.get_deleter().state() == 5);
    }
}
