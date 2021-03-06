//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <mutex>

// class mutex;

// typedef pthread_mutex_t* native_handle_type;
// native_handle_type native_handle();

#include <mutex>
#include <cassert>

int main()
{
    std::mutex m;
    pthread_mutex_t* h = m.native_handle();
    assert(h);
}
