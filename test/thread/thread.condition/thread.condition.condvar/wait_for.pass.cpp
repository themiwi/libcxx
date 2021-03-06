//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <condition_variable>

// class condition_variable;

// template <class Rep, class Period>
//     cv_status
//     wait_for(unique_lock<mutex>& lock,
//              const chrono::duration<Rep, Period>& rel_time);

#include <condition_variable>
#include <mutex>
#include <thread>
#include <chrono>
#include <cassert>

std::condition_variable cv;
std::mutex mut;

int test1 = 0;
int test2 = 0;

int runs = 0;

void f()
{
    typedef std::chrono::system_clock Clock;
    typedef std::chrono::milliseconds milliseconds;
    std::unique_lock<std::mutex> lk(mut);
    assert(test2 == 0);
    test1 = 1;
    cv.notify_one();
    Clock::time_point t0 = Clock::now();
    while (test2 == 0 &&
           cv.wait_for(lk, milliseconds(250)) == std::cv_status::no_timeout)
        ;
    Clock::time_point t1 = Clock::now();
    if (runs == 0)
    {
        assert(t1 - t0 < milliseconds(250));
        assert(test2 != 0);
    }
    else
    {
        assert(t1 - t0 - milliseconds(250) < milliseconds(5));
        assert(test2 == 0);
    }
    ++runs;
}

int main()
{
    {
        std::unique_lock<std::mutex>lk(mut);
        std::thread t(f);
        assert(test1 == 0);
        while (test1 == 0)
            cv.wait(lk);
        assert(test1 != 0);
        test2 = 1;
        lk.unlock();
        cv.notify_one();
        t.join();
    }
    test1 = 0;
    test2 = 0;
    {
        std::unique_lock<std::mutex>lk(mut);
        std::thread t(f);
        assert(test1 == 0);
        while (test1 == 0)
            cv.wait(lk);
        assert(test1 != 0);
        lk.unlock();
        t.join();
    }
}
