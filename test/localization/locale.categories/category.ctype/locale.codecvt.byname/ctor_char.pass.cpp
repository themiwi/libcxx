//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <locale>

// template <> class codecvt_byname<char, char, mbstate_t>

// explicit codecvt_byname(const char* nm, size_t refs = 0);
// explicit codecvt_byname(const string& nm, size_t refs = 0);

#include <locale>
#include <cassert>

typedef std::codecvt_byname<char, char, std::mbstate_t> F;

class my_facet
    : public F
{
public:
    static int count;

    explicit my_facet(const char* nm, std::size_t refs = 0)
        : F(nm, refs) {++count;}
    explicit my_facet(const std::string& nm, std::size_t refs = 0)
        : F(nm, refs) {++count;}

    ~my_facet() {--count;}
};

int my_facet::count = 0;

int main()
{
    {
        std::locale l(std::locale::classic(), new my_facet("en_US"));
        assert(my_facet::count == 1);
    }
    assert(my_facet::count == 0);
    {
        my_facet f("en_US", 1);
        assert(my_facet::count == 1);
        {
            std::locale l(std::locale::classic(), &f);
            assert(my_facet::count == 1);
        }
        assert(my_facet::count == 1);
    }
    assert(my_facet::count == 0);
    {
        std::locale l(std::locale::classic(), new my_facet(std::string("en_US")));
        assert(my_facet::count == 1);
    }
    assert(my_facet::count == 0);
    {
        my_facet f(std::string("en_US"), 1);
        assert(my_facet::count == 1);
        {
            std::locale l(std::locale::classic(), &f);
            assert(my_facet::count == 1);
        }
        assert(my_facet::count == 1);
    }
    assert(my_facet::count == 0);
}
