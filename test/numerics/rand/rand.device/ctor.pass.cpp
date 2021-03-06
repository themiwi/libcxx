//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <random>

// class random_device;

// explicit random_device(const string& token = "/dev/urandom");

#include <random>
#include <cassert>

int main()
{
    try
    {
        std::random_device r("wrong file");
        assert(false);
    }
    catch (const std::system_error& e)
    {
    }
    {
        std::random_device r;
    }
    {
        std::random_device r("/dev/urandom");;
    }
    {
        std::random_device r("/dev/random");;
    }
}
