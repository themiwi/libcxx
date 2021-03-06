//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <istream>

// basic_istream<charT,traits>& get(char_type* s, streamsize n);

#include <istream>
#include <cassert>

template <class CharT>
struct testbuf
    : public std::basic_streambuf<CharT>
{
    typedef std::basic_string<CharT> string_type;
    typedef std::basic_streambuf<CharT> base;
private:
    string_type str_;
public:

    testbuf() {}
    testbuf(const string_type& str)
        : str_(str)
    {
        base::setg(const_cast<CharT*>(str_.data()),
                   const_cast<CharT*>(str_.data()),
                   const_cast<CharT*>(str_.data()) + str_.size());
    }

    CharT* eback() const {return base::eback();}
    CharT* gptr() const {return base::gptr();}
    CharT* egptr() const {return base::egptr();}
};

int main()
{
    {
        testbuf<char> sb("  \n    \n ");
        std::istream is(&sb);
        char s[5];
        is.get(s, 5);
        assert(!is.eof());
        assert(!is.fail());
        assert(std::string(s) == "  ");
        assert(is.gcount() == 2);
        is.get(s, 5);
        assert(!is.eof());
        assert( is.fail());
        assert(std::string(s) == "");
        assert(is.gcount() == 0);
        is.clear();
        assert(is.get() == '\n');
        is.get(s, 5);
        assert(!is.eof());
        assert(!is.fail());
        assert(std::string(s) == "    ");
        assert(is.gcount() == 4);
        assert(is.get() == '\n');
        is.get(s, 5);
        assert( is.eof());
        assert(!is.fail());
        assert(std::string(s) == " ");
        assert(is.gcount() == 1);
    }
    {
        testbuf<wchar_t> sb(L"  \n    \n ");
        std::wistream is(&sb);
        wchar_t s[5];
        is.get(s, 5);
        assert(!is.eof());
        assert(!is.fail());
        assert(std::wstring(s) == L"  ");
        assert(is.gcount() == 2);
        is.get(s, 5);
        assert(!is.eof());
        assert( is.fail());
        assert(std::wstring(s) == L"");
        assert(is.gcount() == 0);
        is.clear();
        assert(is.get() == L'\n');
        is.get(s, 5);
        assert(!is.eof());
        assert(!is.fail());
        assert(std::wstring(s) == L"    ");
        assert(is.gcount() == 4);
        assert(is.get() == L'\n');
        is.get(s, 5);
        assert( is.eof());
        assert(!is.fail());
        assert(std::wstring(s) == L" ");
        assert(is.gcount() == 1);
    }
}
