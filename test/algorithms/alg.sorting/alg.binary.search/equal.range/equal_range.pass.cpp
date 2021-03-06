//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator Iter, class T>
//   requires HasLess<T, Iter::value_type>
//         && HasLess<Iter::value_type, T>
//   pair<Iter, Iter>
//   equal_range(Iter first, Iter last, const T& value);

#include <algorithm>
#include <vector>
#include <cassert>

#include "../../../iterators.h"

template <class Iter, class T>
void
test(Iter first, Iter last, const T& value)
{
    std::pair<Iter, Iter> i = std::equal_range(first, last, value);
    for (Iter j = first; j != i.first; ++j)
        assert(*j < value);
    for (Iter j = i.first; j != last; ++j)
        assert(!(*j < value));
    for (Iter j = first; j != i.second; ++j)
        assert(!(value < *j));
    for (Iter j = i.second; j != last; ++j)
        assert(value < *j);
}

template <class Iter>
void
test()
{
    const unsigned N = 1000;
    const unsigned M = 10;
    std::vector<int> v(N);
    int x = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        v[i] = x;
        if (++x == M)
            x = 0;
    }
    std::sort(v.begin(), v.end());
    for (x = 0; x <= M; ++x)
        test(Iter(v.data()), Iter(v.data()+v.size()), x);
}

int main()
{
    int d[] = {0, 1, 2, 3};
    for (int* e = d; e <= d+4; ++e)
        for (int x = -1; x <= 4; ++x)
            test(d, e, x);

    test<forward_iterator<const int*> >();
    test<bidirectional_iterator<const int*> >();
    test<random_access_iterator<const int*> >();
    test<const int*>();
}
