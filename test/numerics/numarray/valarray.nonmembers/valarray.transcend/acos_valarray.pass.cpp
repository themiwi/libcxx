//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <valarray>

// template<class T> class valarray;

// template<class T>
//   valarray<T>
//   acos(const valarray<T>& x);

#include <valarray>
#include <cassert>
#include <sstream>

bool is_about(double x, double y, int p)
{
    std::ostringstream o;
    o.precision(p);
    scientific(o);
    o << x;
    std::string a = o.str();
    o.str("");
    o << y;
    return a == o.str();
}

int main()
{
    {
        typedef double T;
        T a1[] = {-.9, -.5, 0., .5, .75};
        T a3[] = {2.6905658417935308e+00,
                  2.0943951023931957e+00,
                  1.5707963267948966e+00,
                  1.0471975511965976e+00,
                  7.2273424781341566e-01};
        const unsigned N = sizeof(a1)/sizeof(a1[0]);
        std::valarray<T> v1(a1, N);
        std::valarray<T> v3 = acos(v1);
        assert(v3.size() == v1.size());
        for (int i = 0; i < v3.size(); ++i)
            assert(is_about(v3[i], a3[i], 10));
    }
}
