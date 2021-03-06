//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <strstream>

// class istrstream

// explicit istrstream(char* s);

#include <strstream>
#include <cassert>

int main()
{
    {
        char buf[] = "123 4.5 dog";
        std::istrstream in(buf);
        int i;
        in >> i;
        assert(i == 123);
        double d;
        in >> d;
        assert(d == 4.5);
        std::string s;
        in >> s;
        assert(s == "dog");
        assert(in.eof());
        assert(!in.fail());
        in.clear();
        in.putback('g');
        assert(!in.fail());
        in.putback('g');
        assert(!in.fail());
        assert(buf[9] == 'g');
        assert(buf[10] == 'g');
    }
}
