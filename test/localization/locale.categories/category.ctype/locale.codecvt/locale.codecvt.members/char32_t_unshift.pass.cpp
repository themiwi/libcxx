//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <locale>

// template <> class codecvt<char32_t, char, mbstate_t>

// result unshift(stateT& state,
//                externT* to, externT* to_end, externT*& to_next) const;

#include <locale>
#include <string>
#include <vector>
#include <cassert>

typedef std::codecvt<char32_t, char, std::mbstate_t> F;

int main()
{
    std::locale l = std::locale::classic();
    std::vector<char> to(3);
    const F& f = std::use_facet<F>(l);
    std::mbstate_t mbs;
    char* to_next = 0;
    assert(f.unshift(mbs, to.data(), to.data() + to.size(), to_next) == F::noconv);
    assert(to_next == to.data());
}
