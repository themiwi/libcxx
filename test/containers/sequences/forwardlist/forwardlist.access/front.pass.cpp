//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <forward_list>

// reference       front();
// const_reference front() const;

#include <forward_list>
#include <cassert>
#include <iterator>

int main()
{
    {
        typedef int T;
        typedef std::forward_list<T> C;
        const T t[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        C c(std::begin(t), std::end(t));
        assert(c.front() == 0);
        c.front() = 10;
        assert(c.front() == 10);
        assert(*c.begin() == 10);
    }
    {
        typedef int T;
        typedef std::forward_list<T> C;
        const T t[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        const C c(std::begin(t), std::end(t));
        assert(c.front() == 0);
        assert(*c.begin() == 0);
    }
}
