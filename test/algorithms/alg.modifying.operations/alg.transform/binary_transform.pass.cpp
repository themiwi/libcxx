//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator InIter1, InputIterator InIter2, class OutIter,
//          Callable<auto, const InIter1::value_type&, const InIter2::value_type&> BinaryOp>
//   requires OutputIterator<OutIter, BinaryOp::result_type> && CopyConstructible<BinaryOp>
// OutIter
// transform(InIter1 first1, InIter1 last1, InIter2 first2, OutIter result, BinaryOp binary_op);

#include <algorithm>
#include <functional>
#include <cassert>

#include "../../iterators.h"

template<class InIter1, class InIter2, class OutIter>
void
test()
{
    int ia[] = {0, 1, 2, 3, 4};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    int ib[sa] = {1, 2, 3, 4, 5};
    OutIter r = std::transform(InIter1(ib), InIter1(ib+sa), InIter2(ia),
                               OutIter(ib), std::minus<int>());
    assert(base(r) == ib + sa);
    assert(ib[0] == 1);
    assert(ib[1] == 1);
    assert(ib[2] == 1);
    assert(ib[3] == 1);
    assert(ib[4] == 1);
}

int main()
{
    test<input_iterator<const int*>, input_iterator<const int*>, output_iterator<int*> >();
    test<input_iterator<const int*>, input_iterator<const int*>, input_iterator<int*> >();
    test<input_iterator<const int*>, input_iterator<const int*>, forward_iterator<int*> >();
    test<input_iterator<const int*>, input_iterator<const int*>, bidirectional_iterator<int*> >();
    test<input_iterator<const int*>, input_iterator<const int*>, random_access_iterator<int*> >();
    test<input_iterator<const int*>, input_iterator<const int*>, int*>();

    test<input_iterator<const int*>, forward_iterator<const int*>, output_iterator<int*> >();
    test<input_iterator<const int*>, forward_iterator<const int*>, input_iterator<int*> >();
    test<input_iterator<const int*>, forward_iterator<const int*>, forward_iterator<int*> >();
    test<input_iterator<const int*>, forward_iterator<const int*>, bidirectional_iterator<int*> >();
    test<input_iterator<const int*>, forward_iterator<const int*>, random_access_iterator<int*> >();
    test<input_iterator<const int*>, forward_iterator<const int*>, int*>();

    test<input_iterator<const int*>, bidirectional_iterator<const int*>, output_iterator<int*> >();
    test<input_iterator<const int*>, bidirectional_iterator<const int*>, input_iterator<int*> >();
    test<input_iterator<const int*>, bidirectional_iterator<const int*>, forward_iterator<int*> >();
    test<input_iterator<const int*>, bidirectional_iterator<const int*>, bidirectional_iterator<int*> >();
    test<input_iterator<const int*>, bidirectional_iterator<const int*>, random_access_iterator<int*> >();
    test<input_iterator<const int*>, bidirectional_iterator<const int*>, int*>();

    test<input_iterator<const int*>, random_access_iterator<const int*>, output_iterator<int*> >();
    test<input_iterator<const int*>, random_access_iterator<const int*>, input_iterator<int*> >();
    test<input_iterator<const int*>, random_access_iterator<const int*>, forward_iterator<int*> >();
    test<input_iterator<const int*>, random_access_iterator<const int*>, bidirectional_iterator<int*> >();
    test<input_iterator<const int*>, random_access_iterator<const int*>, random_access_iterator<int*> >();
    test<input_iterator<const int*>, random_access_iterator<const int*>, int*>();

    test<input_iterator<const int*>, const int*, output_iterator<int*> >();
    test<input_iterator<const int*>, const int*, input_iterator<int*> >();
    test<input_iterator<const int*>, const int*, forward_iterator<int*> >();
    test<input_iterator<const int*>, const int*, bidirectional_iterator<int*> >();
    test<input_iterator<const int*>, const int*, random_access_iterator<int*> >();
    test<input_iterator<const int*>, const int*, int*>();

    test<forward_iterator<const int*>, input_iterator<const int*>, output_iterator<int*> >();
    test<forward_iterator<const int*>, input_iterator<const int*>, input_iterator<int*> >();
    test<forward_iterator<const int*>, input_iterator<const int*>, forward_iterator<int*> >();
    test<forward_iterator<const int*>, input_iterator<const int*>, bidirectional_iterator<int*> >();
    test<forward_iterator<const int*>, input_iterator<const int*>, random_access_iterator<int*> >();
    test<forward_iterator<const int*>, input_iterator<const int*>, int*>();

    test<forward_iterator<const int*>, forward_iterator<const int*>, output_iterator<int*> >();
    test<forward_iterator<const int*>, forward_iterator<const int*>, input_iterator<int*> >();
    test<forward_iterator<const int*>, forward_iterator<const int*>, forward_iterator<int*> >();
    test<forward_iterator<const int*>, forward_iterator<const int*>, bidirectional_iterator<int*> >();
    test<forward_iterator<const int*>, forward_iterator<const int*>, random_access_iterator<int*> >();
    test<forward_iterator<const int*>, forward_iterator<const int*>, int*>();

    test<forward_iterator<const int*>, bidirectional_iterator<const int*>, output_iterator<int*> >();
    test<forward_iterator<const int*>, bidirectional_iterator<const int*>, input_iterator<int*> >();
    test<forward_iterator<const int*>, bidirectional_iterator<const int*>, forward_iterator<int*> >();
    test<forward_iterator<const int*>, bidirectional_iterator<const int*>, bidirectional_iterator<int*> >();
    test<forward_iterator<const int*>, bidirectional_iterator<const int*>, random_access_iterator<int*> >();
    test<forward_iterator<const int*>, bidirectional_iterator<const int*>, int*>();

    test<forward_iterator<const int*>, random_access_iterator<const int*>, output_iterator<int*> >();
    test<forward_iterator<const int*>, random_access_iterator<const int*>, input_iterator<int*> >();
    test<forward_iterator<const int*>, random_access_iterator<const int*>, forward_iterator<int*> >();
    test<forward_iterator<const int*>, random_access_iterator<const int*>, bidirectional_iterator<int*> >();
    test<forward_iterator<const int*>, random_access_iterator<const int*>, random_access_iterator<int*> >();
    test<forward_iterator<const int*>, random_access_iterator<const int*>, int*>();

    test<forward_iterator<const int*>, const int*, output_iterator<int*> >();
    test<forward_iterator<const int*>, const int*, input_iterator<int*> >();
    test<forward_iterator<const int*>, const int*, forward_iterator<int*> >();
    test<forward_iterator<const int*>, const int*, bidirectional_iterator<int*> >();
    test<forward_iterator<const int*>, const int*, random_access_iterator<int*> >();
    test<forward_iterator<const int*>, const int*, int*>();

    test<bidirectional_iterator<const int*>, input_iterator<const int*>, output_iterator<int*> >();
    test<bidirectional_iterator<const int*>, input_iterator<const int*>, input_iterator<int*> >();
    test<bidirectional_iterator<const int*>, input_iterator<const int*>, forward_iterator<int*> >();
    test<bidirectional_iterator<const int*>, input_iterator<const int*>, bidirectional_iterator<int*> >();
    test<bidirectional_iterator<const int*>, input_iterator<const int*>, random_access_iterator<int*> >();
    test<bidirectional_iterator<const int*>, input_iterator<const int*>, int*>();

    test<bidirectional_iterator<const int*>, forward_iterator<const int*>, output_iterator<int*> >();
    test<bidirectional_iterator<const int*>, forward_iterator<const int*>, input_iterator<int*> >();
    test<bidirectional_iterator<const int*>, forward_iterator<const int*>, forward_iterator<int*> >();
    test<bidirectional_iterator<const int*>, forward_iterator<const int*>, bidirectional_iterator<int*> >();
    test<bidirectional_iterator<const int*>, forward_iterator<const int*>, random_access_iterator<int*> >();
    test<bidirectional_iterator<const int*>, forward_iterator<const int*>, int*>();

    test<bidirectional_iterator<const int*>, bidirectional_iterator<const int*>, output_iterator<int*> >();
    test<bidirectional_iterator<const int*>, bidirectional_iterator<const int*>, input_iterator<int*> >();
    test<bidirectional_iterator<const int*>, bidirectional_iterator<const int*>, forward_iterator<int*> >();
    test<bidirectional_iterator<const int*>, bidirectional_iterator<const int*>, bidirectional_iterator<int*> >();
    test<bidirectional_iterator<const int*>, bidirectional_iterator<const int*>, random_access_iterator<int*> >();
    test<bidirectional_iterator<const int*>, bidirectional_iterator<const int*>, int*>();

    test<bidirectional_iterator<const int*>, random_access_iterator<const int*>, output_iterator<int*> >();
    test<bidirectional_iterator<const int*>, random_access_iterator<const int*>, input_iterator<int*> >();
    test<bidirectional_iterator<const int*>, random_access_iterator<const int*>, forward_iterator<int*> >();
    test<bidirectional_iterator<const int*>, random_access_iterator<const int*>, bidirectional_iterator<int*> >();
    test<bidirectional_iterator<const int*>, random_access_iterator<const int*>, random_access_iterator<int*> >();
    test<bidirectional_iterator<const int*>, random_access_iterator<const int*>, int*>();

    test<bidirectional_iterator<const int*>, const int*, output_iterator<int*> >();
    test<bidirectional_iterator<const int*>, const int*, input_iterator<int*> >();
    test<bidirectional_iterator<const int*>, const int*, forward_iterator<int*> >();
    test<bidirectional_iterator<const int*>, const int*, bidirectional_iterator<int*> >();
    test<bidirectional_iterator<const int*>, const int*, random_access_iterator<int*> >();
    test<bidirectional_iterator<const int*>, const int*, int*>();

    test<random_access_iterator<const int*>, input_iterator<const int*>, output_iterator<int*> >();
    test<random_access_iterator<const int*>, input_iterator<const int*>, input_iterator<int*> >();
    test<random_access_iterator<const int*>, input_iterator<const int*>, forward_iterator<int*> >();
    test<random_access_iterator<const int*>, input_iterator<const int*>, bidirectional_iterator<int*> >();
    test<random_access_iterator<const int*>, input_iterator<const int*>, random_access_iterator<int*> >();
    test<random_access_iterator<const int*>, input_iterator<const int*>, int*>();

    test<random_access_iterator<const int*>, forward_iterator<const int*>, output_iterator<int*> >();
    test<random_access_iterator<const int*>, forward_iterator<const int*>, input_iterator<int*> >();
    test<random_access_iterator<const int*>, forward_iterator<const int*>, forward_iterator<int*> >();
    test<random_access_iterator<const int*>, forward_iterator<const int*>, bidirectional_iterator<int*> >();
    test<random_access_iterator<const int*>, forward_iterator<const int*>, random_access_iterator<int*> >();
    test<random_access_iterator<const int*>, forward_iterator<const int*>, int*>();

    test<random_access_iterator<const int*>, bidirectional_iterator<const int*>, output_iterator<int*> >();
    test<random_access_iterator<const int*>, bidirectional_iterator<const int*>, input_iterator<int*> >();
    test<random_access_iterator<const int*>, bidirectional_iterator<const int*>, forward_iterator<int*> >();
    test<random_access_iterator<const int*>, bidirectional_iterator<const int*>, bidirectional_iterator<int*> >();
    test<random_access_iterator<const int*>, bidirectional_iterator<const int*>, random_access_iterator<int*> >();
    test<random_access_iterator<const int*>, bidirectional_iterator<const int*>, int*>();

    test<random_access_iterator<const int*>, random_access_iterator<const int*>, output_iterator<int*> >();
    test<random_access_iterator<const int*>, random_access_iterator<const int*>, input_iterator<int*> >();
    test<random_access_iterator<const int*>, random_access_iterator<const int*>, forward_iterator<int*> >();
    test<random_access_iterator<const int*>, random_access_iterator<const int*>, bidirectional_iterator<int*> >();
    test<random_access_iterator<const int*>, random_access_iterator<const int*>, random_access_iterator<int*> >();
    test<random_access_iterator<const int*>, random_access_iterator<const int*>, int*>();

    test<random_access_iterator<const int*>, const int*, output_iterator<int*> >();
    test<random_access_iterator<const int*>, const int*, input_iterator<int*> >();
    test<random_access_iterator<const int*>, const int*, forward_iterator<int*> >();
    test<random_access_iterator<const int*>, const int*, bidirectional_iterator<int*> >();
    test<random_access_iterator<const int*>, const int*, random_access_iterator<int*> >();
    test<random_access_iterator<const int*>, const int*, int*>();

    test<const int*, input_iterator<const int*>, output_iterator<int*> >();
    test<const int*, input_iterator<const int*>, input_iterator<int*> >();
    test<const int*, input_iterator<const int*>, forward_iterator<int*> >();
    test<const int*, input_iterator<const int*>, bidirectional_iterator<int*> >();
    test<const int*, input_iterator<const int*>, random_access_iterator<int*> >();
    test<const int*, input_iterator<const int*>, int*>();

    test<const int*, forward_iterator<const int*>, output_iterator<int*> >();
    test<const int*, forward_iterator<const int*>, input_iterator<int*> >();
    test<const int*, forward_iterator<const int*>, forward_iterator<int*> >();
    test<const int*, forward_iterator<const int*>, bidirectional_iterator<int*> >();
    test<const int*, forward_iterator<const int*>, random_access_iterator<int*> >();
    test<const int*, forward_iterator<const int*>, int*>();

    test<const int*, bidirectional_iterator<const int*>, output_iterator<int*> >();
    test<const int*, bidirectional_iterator<const int*>, input_iterator<int*> >();
    test<const int*, bidirectional_iterator<const int*>, forward_iterator<int*> >();
    test<const int*, bidirectional_iterator<const int*>, bidirectional_iterator<int*> >();
    test<const int*, bidirectional_iterator<const int*>, random_access_iterator<int*> >();
    test<const int*, bidirectional_iterator<const int*>, int*>();

    test<const int*, random_access_iterator<const int*>, output_iterator<int*> >();
    test<const int*, random_access_iterator<const int*>, input_iterator<int*> >();
    test<const int*, random_access_iterator<const int*>, forward_iterator<int*> >();
    test<const int*, random_access_iterator<const int*>, bidirectional_iterator<int*> >();
    test<const int*, random_access_iterator<const int*>, random_access_iterator<int*> >();
    test<const int*, random_access_iterator<const int*>, int*>();

    test<const int*, const int*, output_iterator<int*> >();
    test<const int*, const int*, input_iterator<int*> >();
    test<const int*, const int*, forward_iterator<int*> >();
    test<const int*, const int*, bidirectional_iterator<int*> >();
    test<const int*, const int*, random_access_iterator<int*> >();
    test<const int*, const int*, int*>();
}
