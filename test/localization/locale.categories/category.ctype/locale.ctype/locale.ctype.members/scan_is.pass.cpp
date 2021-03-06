//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <locale>

// template <class charT> class ctype;

// const charT* scan_is(mask m, const charT* low, const charT* high) const;

#include <locale>
#include <string>
#include <vector>
#include <cassert>

#include <stdio.h>

int main()
{
    std::locale l = std::locale::classic();
    {
        typedef std::ctype<wchar_t> F;
        const F& f = std::use_facet<F>(l);
        const std::wstring in(L" A\x07.a1");
        std::vector<F::mask> m(in.size());
        assert(f.scan_is(F::space, in.data(), in.data() + in.size()) - in.data() == 0);
        assert(f.scan_is(F::print, in.data(), in.data() + in.size()) - in.data() == 0);
        assert(f.scan_is(F::cntrl, in.data(), in.data() + in.size()) - in.data() == 2);
        assert(f.scan_is(F::upper, in.data(), in.data() + in.size()) - in.data() == 1);
        assert(f.scan_is(F::lower, in.data(), in.data() + in.size()) - in.data() == 4);
        assert(f.scan_is(F::alpha, in.data(), in.data() + in.size()) - in.data() == 1);
        assert(f.scan_is(F::digit, in.data(), in.data() + in.size()) - in.data() == 5);
        assert(f.scan_is(F::punct, in.data(), in.data() + in.size()) - in.data() == 3);
        assert(f.scan_is(F::xdigit, in.data(), in.data() + in.size()) - in.data() == 1);
        assert(f.scan_is(F::blank, in.data(), in.data() + in.size()) - in.data() == 0);
        assert(f.scan_is(F::alnum, in.data(), in.data() + in.size()) - in.data() == 1);
        assert(f.scan_is(F::graph, in.data(), in.data() + in.size()) - in.data() == 1);
    }
}
