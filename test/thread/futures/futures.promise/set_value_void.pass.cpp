//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <future>

// class promise<R>

// void promise<void>::set_value();

#include <future>
#include <cassert>

int main()
{
    {
        typedef void T;
        std::promise<T> p;
        std::future<T> f = p.get_future();
        p.set_value();
        f.get();
        try
        {
            p.set_value();
            assert(false);
        }
        catch (const std::future_error& e)
        {
            assert(e.code() == make_error_code(std::future_errc::promise_already_satisfied));
        }
    }
}
