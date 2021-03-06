//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <fstream>

// template <class charT, class traits = char_traits<charT> >
// class basic_ifstream

// basic_filebuf<charT,traits>* rdbuf() const;

#include <fstream>
#include <cassert>

int main()
{
    {
        std::ifstream fs("test.dat");
        std::filebuf* fb = fs.rdbuf();
        assert(fb->sgetc() == 'r');
    }
    {
        std::wifstream fs("test.dat");
        std::wfilebuf* fb = fs.rdbuf();
        assert(fb->sgetc() == L'r');
    }
}
