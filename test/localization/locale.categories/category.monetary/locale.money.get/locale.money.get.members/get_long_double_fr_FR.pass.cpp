//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <locale>

// class money_get<charT, InputIterator>

// iter_type get(iter_type b, iter_type e, bool intl, ios_base& iob,
//               ios_base::iostate& err, long double& v) const;

#include <locale>
#include <ios>
#include <streambuf>
#include <cassert>
#include "iterators.h"

typedef std::money_get<char, input_iterator<const char*> > Fn;

class my_facet
    : public Fn
{
public:
    explicit my_facet(std::size_t refs = 0)
        : Fn(refs) {}
};

typedef std::money_get<wchar_t, input_iterator<const wchar_t*> > Fw;

class my_facetw
    : public Fw
{
public:
    explicit my_facetw(std::size_t refs = 0)
        : Fw(refs) {}
};

int main()
{
    std::ios ios(0);
    std::string loc_name("fr_FR");
    ios.imbue(std::locale(ios.getloc(),
                          new std::moneypunct_byname<char, false>(loc_name)));
    ios.imbue(std::locale(ios.getloc(),
                          new std::moneypunct_byname<char, true>(loc_name)));
    ios.imbue(std::locale(ios.getloc(),
                          new std::moneypunct_byname<wchar_t, false>(loc_name)));
    ios.imbue(std::locale(ios.getloc(),
                          new std::moneypunct_byname<wchar_t, true>(loc_name)));
    {
        const my_facet f(1);
        // char, national
        {   // zero
            std::string v = "0,00";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
        }
        {   // negative one
            std::string v = "0,01 -";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
        }
        {   // positive
            std::string v = "1 234 567,89 ";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
        }
        {   // negative
            std::string v = "1 234 567,89 -";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
        }
        {   // negative
            std::string v = "1234567,89 -";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
        }
        {   // zero, showbase
            std::string v = "0,00 Eu";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
        }
        {   // zero, showbase
            std::string v = "0,00 Eu";
            showbase(ios);
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
            noshowbase(ios);
        }
        {   // negative one, showbase
            std::string v = "0,01 Eu-";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
        }
        {   // negative one, showbase
            std::string v = "0,01 Eu-";
            showbase(ios);
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
            noshowbase(ios);
        }
        {   // positive, showbase
            std::string v = "1 234 567,89 Eu";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
        }
        {   // positive, showbase
            std::string v = "1 234 567,89 Eu";
            showbase(ios);
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::string v = "1 234 567,89 Eu-";
            showbase(ios);
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::string v = "1 234 567,89 EUR -";
            showbase(ios);
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + 14);
            assert(err == std::ios_base::failbit);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::string v = "1 234 567,89 EUR -";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + 14);
            assert(err == std::ios_base::goodbit);
            assert(ex == 123456789);
        }
    }
    {
        const my_facet f(1);
        // char, international
        {   // zero
            std::string v = "0,00";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
        }
        {   // negative one
            std::string v = "0,01 -";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
        }
        {   // positive
            std::string v = "1 234 567,89 ";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
        }
        {   // negative
            std::string v = "1 234 567,89 -";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
        }
        {   // negative
            std::string v = "1234567,89 -";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
        }
        {   // zero, showbase
            std::string v = "0,00 EUR ";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
        }
        {   // zero, showbase
            std::string v = "0,00 EUR ";
            showbase(ios);
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
            noshowbase(ios);
        }
        {   // negative one, showbase
            std::string v = "0,01 EUR -";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
        }
        {   // negative one, showbase
            std::string v = "0,01 EUR -";
            showbase(ios);
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
            noshowbase(ios);
        }
        {   // positive, showbase
            std::string v = "1 234 567,89 EUR ";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
        }
        {   // positive, showbase
            std::string v = "1 234 567,89 EUR ";
            showbase(ios);
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::string v = "1 234 567,89 EUR -";
            showbase(ios);
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::string v = "1 234 567,89 Eu-";
            showbase(ios);
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + 14);
            assert(err == std::ios_base::failbit);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::string v = "1 234 567,89 Eu-";
            typedef input_iterator<const char*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + 14);
            assert(err == std::ios_base::goodbit);
            assert(ex == 123456789);
        }
    }
    {
        const my_facetw f(1);
        // wchar_t, national
        {   // zero
            std::wstring v = L"0,00";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
        }
        {   // negative one
            std::wstring v = L"0,01 -";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
        }
        {   // positive
            std::wstring v = L"1 234 567,89 ";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
        }
        {   // negative
            std::wstring v = L"1 234 567,89 -";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
        }
        {   // negative
            std::wstring v = L"1234567,89 -";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
        }
        {   // zero, showbase
            std::wstring v = L"0,00 Eu";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
        }
        {   // zero, showbase
            std::wstring v = L"0,00 Eu";
            showbase(ios);
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
            noshowbase(ios);
        }
        {   // negative one, showbase
            std::wstring v = L"0,01 Eu-";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
        }
        {   // negative one, showbase
            std::wstring v = L"0,01 Eu-";
            showbase(ios);
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
            noshowbase(ios);
        }
        {   // positive, showbase
            std::wstring v = L"1 234 567,89 Eu";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
        }
        {   // positive, showbase
            std::wstring v = L"1 234 567,89 Eu";
            showbase(ios);
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::wstring v = L"1 234 567,89 Eu-";
            showbase(ios);
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::wstring v = L"1 234 567,89 EUR -";
            showbase(ios);
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + 14);
            assert(err == std::ios_base::failbit);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::wstring v = L"1 234 567,89 EUR -";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                false, ios, err, ex);
            assert(iter.base() == v.data() + 14);
            assert(err == std::ios_base::goodbit);
            assert(ex == 123456789);
        }
    }
    {
        const my_facetw f(1);
        // wchar_t, international
        {   // zero
            std::wstring v = L"0,00";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
        }
        {   // negative one
            std::wstring v = L"0,01 -";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
        }
        {   // positive
            std::wstring v = L"1 234 567,89 ";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
        }
        {   // negative
            std::wstring v = L"1 234 567,89 -";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
        }
        {   // negative
            std::wstring v = L"1234567,89 -";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
        }
        {   // zero, showbase
            std::wstring v = L"0,00 EUR ";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
        }
        {   // zero, showbase
            std::wstring v = L"0,00 EUR ";
            showbase(ios);
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 0);
            noshowbase(ios);
        }
        {   // negative one, showbase
            std::wstring v = L"0,01 EUR -";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
        }
        {   // negative one, showbase
            std::wstring v = L"0,01 EUR -";
            showbase(ios);
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -1);
            noshowbase(ios);
        }
        {   // positive, showbase
            std::wstring v = L"1 234 567,89 EUR ";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
        }
        {   // positive, showbase
            std::wstring v = L"1 234 567,89 EUR ";
            showbase(ios);
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == 123456789);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::wstring v = L"1 234 567,89 EUR -";
            showbase(ios);
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + v.size());
            assert(err == std::ios_base::eofbit);
            assert(ex == -123456789);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::wstring v = L"1 234 567,89 Eu-";
            showbase(ios);
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + 14);
            assert(err == std::ios_base::failbit);
            noshowbase(ios);
        }
        {   // negative, showbase
            std::wstring v = L"1 234 567,89 Eu-";
            typedef input_iterator<const wchar_t*> I;
            long double ex;
            std::ios_base::iostate err = std::ios_base::goodbit;
            I iter = f.get(I(v.data()), I(v.data() + v.size()),
                                                true, ios, err, ex);
            assert(iter.base() == v.data() + 14);
            assert(err == std::ios_base::goodbit);
            assert(ex == 123456789);
        }
    }
}
