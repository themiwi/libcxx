//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <condition_variable>

// class condition_variable_any;

// template <class Lock, class Rep, class Period, class Predicate>
//   bool
//   wait_for(Lock& lock, const chrono::duration<Rep, Period>& rel_time,
//            Predicate pred);

#include <condition_variable>
#include <mutex>
#include <thread>
#include <chrono>
#include <cassert>

class Pred
{
    int& i_;
public:
    explicit Pred(int& i) : i_(i) {}

    bool operator()() {return i_ != 0;}
};

std::condition_variable_any cv;

typedef std::timed_mutex L0;
typedef std::unique_lock<L0> L1;

L0 m0;

int test1 = 0;
int test2 = 0;

int runs = 0;

void f()
{
    typedef std::chrono::system_clock Clock;
    typedef std::chrono::milliseconds milliseconds;
    L1 lk(m0);
    assert(test2 == 0);
    test1 = 1;
    cv.notify_one();
    Clock::time_point t0 = Clock::now();
    bool r = cv.wait_for(lk, milliseconds(250), Pred(test2));
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
        L1 lk(m0);
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
        L1 lk(m0);
        std::thread t(f);
        assert(test1 == 0);
        while (test1 == 0)
            cv.wait(lk);
        assert(test1 != 0);
        lk.unlock();
        t.join();
    }
}
