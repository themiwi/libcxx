//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <system_error>

// class error_condition

// string message() const;

#include <system_error>
#include <string>
#include <cassert>

int main()
{
    const std::error_condition ec(6, std::generic_category());
    assert(ec.message() == std::generic_category().message(6));
}
