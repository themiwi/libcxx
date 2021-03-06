//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <mutex>

// template <class Mutex> class unique_lock;

// template <class Clock, class Duration>
//   bool try_lock_until(const chrono::time_point<Clock, Duration>& abs_time);

#include <mutex>
#include <cassert>

bool try_lock_until_called = false;

struct mutex
{
    template <class Clock, class Duration>
        bool try_lock_until(const std::chrono::time_point<Clock, Duration>& abs_time)
    {
        typedef std::chrono::milliseconds ms;
        assert(Clock::now() - abs_time < ms(5));
        try_lock_until_called = !try_lock_until_called;
        return try_lock_until_called;
    }
    void unlock() {}
};

mutex m;

int main()
{
    typedef std::chrono::monotonic_clock Clock;
    std::unique_lock<mutex> lk(m, std::defer_lock);
    assert(lk.try_lock_until(Clock::now()) == true);
    assert(try_lock_until_called == true);
    assert(lk.owns_lock() == true);
    try
    {
        lk.try_lock_until(Clock::now());
        assert(false);
    }
    catch (std::system_error& e)
    {
        assert(e.code().value() == EDEADLK);
    }
    lk.unlock();
    assert(lk.try_lock_until(Clock::now()) == false);
    assert(try_lock_until_called == false);
    assert(lk.owns_lock() == false);
    lk.release();
    try
    {
        lk.try_lock_until(Clock::now());
        assert(false);
    }
    catch (std::system_error& e)
    {
        assert(e.code().value() == EPERM);
    }
}
