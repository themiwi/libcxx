//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <iterator>

// front_insert_iterator

// front_insert_iterator<Cont>&
//   operator=(const Cont::value_type& value);

#include <iterator>
#include <list>
#include <cassert>

template <class C>
void
test(C c)
{
    const typename C::value_type v = typename C::value_type();
    std::front_insert_iterator<C> i(c);
    i = v;
    assert(c.front() == v);
}

class Copyable
{
    int data_;
public:
    Copyable() : data_(0) {}
    ~Copyable() {data_ = -1;}

    friend bool operator==(const Copyable& x, const Copyable& y)
        {return x.data_ == y.data_;}
};

int main()
{
    test(std::list<Copyable>());
}
