//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <future>

// const error_category& future_category();

#include <future>
#include <cstring>
#include <cassert>

int main()
{
    const std::error_category& ec = std::future_category();
    assert(std::strcmp(ec.name(), "future") == 0);
}
