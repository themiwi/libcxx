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

// void notify_all();

#include <condition_variable>
#include <mutex>
#include <thread>
#include <cassert>

std::condition_variable cv;
std::mutex mut;

int test0 = 0;
int test1 = 0;
int test2 = 0;

void f1()
{
    std::unique_lock<std::mutex> lk(mut);
    assert(test1 == 0);
    while (test1 == 0)
        cv.wait(lk);
    assert(test1 == 1);
    test1 = 2;
}

void f2()
{
    std::unique_lock<std::mutex> lk(mut);
    assert(test2 == 0);
    while (test2 == 0)
        cv.wait(lk);
    assert(test2 == 1);
    test2 = 2;
}

int main()
{
    std::thread t1(f1);
    std::thread t2(f2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    {
        std::unique_lock<std::mutex>lk(mut);
        test1 = 1;
        test2 = 1;
    }
    cv.notify_all();
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::unique_lock<std::mutex>lk(mut);
    }
    t1.join();
    t2.join();
    assert(test1 == 2);
    assert(test2 == 2);
}
