//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <ios>

// class ios_base

// locale imbue(const locale& loc);

#include <ios>
#include <string>
#include <locale>
#include <cassert>

class test
    : public std::ios
{
public:
    test()
    {
        init(0);
    }
};

bool f1_called = false;
bool f2_called = false;
bool f3_called = false;

void f1(std::ios_base::event ev, std::ios_base& stream, int index)
{
    if (ev == std::ios_base::imbue_event)
    {
        assert(!f1_called);
        assert( f2_called);
        assert( f3_called);
        assert(stream.getloc().name() == "en_US");
        assert(index == 4);
        f1_called = true;
    }
}

void f2(std::ios_base::event ev, std::ios_base& stream, int index)
{
    if (ev == std::ios_base::imbue_event)
    {
        assert(!f1_called);
        assert(!f2_called);
        assert( f3_called);
        assert(stream.getloc().name() == "en_US");
        assert(index == 5);
        f2_called = true;
    }
}

void f3(std::ios_base::event ev, std::ios_base& stream, int index)
{
    if (ev == std::ios_base::imbue_event)
    {
        assert(!f1_called);
        assert(!f2_called);
        assert(!f3_called);
        assert(stream.getloc().name() == "en_US");
        assert(index == 6);
        f3_called = true;
    }
}

int main()
{
    test t;
    std::ios_base& b = t;
    b.register_callback(f1, 4);
    b.register_callback(f2, 5);
    b.register_callback(f3, 6);
    std::locale l = b.imbue(std::locale("en_US"));
    assert(l.name() == std::string("C"));
    assert(b.getloc().name() == std::string("en_US"));
    assert(f1_called);
    assert(f2_called);
    assert(f3_called);
}
