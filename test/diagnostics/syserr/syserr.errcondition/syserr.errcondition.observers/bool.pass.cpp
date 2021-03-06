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

// explicit operator bool() const;

#include <system_error>
#include <string>
#include <cassert>

int main()
{
    {
        const std::error_condition ec(6, std::generic_category());
        assert(static_cast<bool>(ec));
    }
    {
        const std::error_condition ec(0, std::generic_category());
        assert(!static_cast<bool>(ec));
    }
}
