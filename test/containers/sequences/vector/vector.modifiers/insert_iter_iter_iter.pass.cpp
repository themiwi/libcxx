//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <vector>

// template <class Iter>
//   iterator insert(const_iterator position, Iter first, Iter last);

#include <vector>
#include <cassert>
#include "../../../stack_allocator.h"
#include "../../../iterators.h"

int main()
{
    {
        std::vector<int> v(100);
        int a[] = {1, 2, 3, 4, 5};
        const int N = sizeof(a)/sizeof(a[0]);
        std::vector<int>::iterator i = v.insert(v.cbegin() + 10, input_iterator<const int*>(a),
                                        input_iterator<const int*>(a+N));
        assert(v.size() == 100 + N);
        assert(i == v.begin() + 10);
        int j;
        for (j = 0; j < 10; ++j)
            assert(v[j] == 0);
        for (int k = 0; k < N; ++j, ++k)
            assert(v[j] == a[k]);
        for (; j < 105; ++j)
            assert(v[j] == 0);
    }
    {
        std::vector<int> v(100);
        int a[] = {1, 2, 3, 4, 5};
        const int N = sizeof(a)/sizeof(a[0]);
        std::vector<int>::iterator i = v.insert(v.cbegin() + 10, forward_iterator<const int*>(a),
                                        forward_iterator<const int*>(a+N));
        assert(v.size() == 100 + N);
        assert(i == v.begin() + 10);
        int j;
        for (j = 0; j < 10; ++j)
            assert(v[j] == 0);
        for (int k = 0; k < N; ++j, ++k)
            assert(v[j] == a[k]);
        for (; j < 105; ++j)
            assert(v[j] == 0);
    }
    {
        std::vector<int, stack_allocator<int, 308> > v(100);
        int a[] = {1, 2, 3, 4, 5};
        const int N = sizeof(a)/sizeof(a[0]);
        std::vector<int>::iterator i = v.insert(v.cbegin() + 10, input_iterator<const int*>(a),
                                        input_iterator<const int*>(a+N));
        assert(v.size() == 100 + N);
        assert(i == v.begin() + 10);
        int j;
        for (j = 0; j < 10; ++j)
            assert(v[j] == 0);
        for (int k = 0; k < N; ++j, ++k)
            assert(v[j] == a[k]);
        for (; j < 105; ++j)
            assert(v[j] == 0);
    }
    {
        std::vector<int, stack_allocator<int, 300> > v(100);
        int a[] = {1, 2, 3, 4, 5};
        const int N = sizeof(a)/sizeof(a[0]);
        std::vector<int>::iterator i = v.insert(v.cbegin() + 10, forward_iterator<const int*>(a),
                                        forward_iterator<const int*>(a+N));
        assert(v.size() == 100 + N);
        assert(i == v.begin() + 10);
        int j;
        for (j = 0; j < 10; ++j)
            assert(v[j] == 0);
        for (int k = 0; k < N; ++j, ++k)
            assert(v[j] == a[k]);
        for (; j < 105; ++j)
            assert(v[j] == 0);
    }
}
