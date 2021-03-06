//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// test <stdbool.h>

#include <stdbool.h>

#ifndef __bool_true_false_are_defined
#error __bool_true_false_are_defined not defined
#endif

#ifdef bool
#error bool should not be defined
#endif

#ifdef true
#error true should not be defined
#endif

#ifdef false
#error false should not be defined
#endif

int main()
{
}
