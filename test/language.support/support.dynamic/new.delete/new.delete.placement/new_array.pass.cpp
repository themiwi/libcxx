//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// test placement new array

#include <new>
#include <cassert>

int A_constructed = 0;

struct A
{
    A() {++A_constructed;}
    ~A() {--A_constructed;}
};

int main()
{
    char buf[3*sizeof(A)];

    A* ap = new(buf) A[3];
    assert((char*)ap == buf);
    assert(A_constructed == 3);
}
