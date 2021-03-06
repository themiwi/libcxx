//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <random>

// class seed_seq
// {
// public:
//     // types
//     typedef uint_least32_t result_type;

#include <random>
#include <type_traits>

int main()
{
    static_assert((std::is_same<std::seed_seq::result_type, std::uint_least32_t>::value), "");
}
