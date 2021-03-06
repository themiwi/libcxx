//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <locale>

// class moneypunct<charT, International>

// string_type negative_sign() const;

// The C++ and C standards are silent.
//   On this one, commen sense is the guideline.
//   If customers complain, I'll endeavor to minimize customer complaints

#include <locale>
#include <limits>
#include <cassert>

typedef std::moneypunct<char> F;

class Fnf
    : public std::moneypunct<char, false>
{
public:
    explicit Fnf(std::size_t refs = 0)
        : std::moneypunct<char, false>(refs) {}
};

class Fnt
    : public std::moneypunct<char, true>
{
public:
    explicit Fnt(std::size_t refs = 0)
        : std::moneypunct<char, true>(refs) {}
};

class Fwf
    : public std::moneypunct<wchar_t, false>
{
public:
    explicit Fwf(std::size_t refs = 0)
        : std::moneypunct<wchar_t, false>(refs) {}
};

class Fwt
    : public std::moneypunct<wchar_t, true>
{
public:
    explicit Fwt(std::size_t refs = 0)
        : std::moneypunct<wchar_t, true>(refs) {}
};

int main()
{
    {
        Fnf f(1);
        assert(f.negative_sign() == "-");
    }
    {
        Fnt f(1);
        assert(f.negative_sign() == "-");
    }
    {
        Fwf f(1);
        assert(f.negative_sign() == L"-");
    }
    {
        Fwt f(1);
        assert(f.negative_sign() == L"-");
    }
}
