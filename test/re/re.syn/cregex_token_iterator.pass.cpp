//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <regex>

// typedef regex_token_iterator<const char*>   cregex_token_iterator;

#include <regex>
#include <type_traits>

int main()
{
    static_assert((std::is_same<std::regex_token_iterator<const char*>, std::cregex_token_iterator>::value), "");
}
