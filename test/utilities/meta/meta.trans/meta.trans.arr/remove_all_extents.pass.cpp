//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// type_traits

// remove_all_extents

#include <type_traits>

enum Enum {zero, one_};

int main()
{
    static_assert((std::is_same<std::remove_all_extents<int>::type, int>::value), "");
    static_assert((std::is_same<std::remove_all_extents<const Enum>::type, const Enum>::value), "");
    static_assert((std::is_same<std::remove_all_extents<int[]>::type, int>::value), "");
    static_assert((std::is_same<std::remove_all_extents<const int[]>::type, const int>::value), "");
    static_assert((std::is_same<std::remove_all_extents<int[3]>::type, int>::value), "");
    static_assert((std::is_same<std::remove_all_extents<const int[3]>::type, const int>::value), "");
    static_assert((std::is_same<std::remove_all_extents<int[][3]>::type, int>::value), "");
    static_assert((std::is_same<std::remove_all_extents<const int[][3]>::type, const int>::value), "");
    static_assert((std::is_same<std::remove_all_extents<int[2][3]>::type, int>::value), "");
    static_assert((std::is_same<std::remove_all_extents<const int[2][3]>::type, const int>::value), "");
    static_assert((std::is_same<std::remove_all_extents<int[1][2][3]>::type, int>::value), "");
    static_assert((std::is_same<std::remove_all_extents<const int[1][2][3]>::type, const int>::value), "");
}
