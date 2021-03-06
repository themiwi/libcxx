//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <random>

// template<class RealType = double>
// class cauchy_distribution

// template<class _URNG> result_type operator()(_URNG& g, const param_type& parm);

#include <random>
#include <cassert>
#include <vector>
#include <algorithm>

double
f(double x, double a, double b)
{
    return 1/3.1415926535897932 * std::atan((x - a)/b) + .5;
}

int main()
{
    {
        typedef std::cauchy_distribution<> D;
        typedef D::param_type P;
        typedef std::mt19937 G;
        G g;
        const double a = 10;
        const double b = .5;
        D d;
        P p(a, b);
        const int N = 1000000;
        std::vector<D::result_type> u;
        for (int i = 0; i < N; ++i)
            u.push_back(d(g, p));
        std::sort(u.begin(), u.end());
        for (int i = 0; i < N; ++i)
            assert(std::abs(f(u[i], a, b) - double(i)/N) < .001);
    }
    {
        typedef std::cauchy_distribution<> D;
        typedef D::param_type P;
        typedef std::mt19937 G;
        G g;
        const double a = -1.5;
        const double b = 1;
        D d;
        P p(a, b);
        const int N = 1000000;
        std::vector<D::result_type> u;
        for (int i = 0; i < N; ++i)
            u.push_back(d(g, p));
        std::sort(u.begin(), u.end());
        for (int i = 0; i < N; ++i)
            assert(std::abs(f(u[i], a, b) - double(i)/N) < .001);
    }
    {
        typedef std::cauchy_distribution<> D;
        typedef D::param_type P;
        typedef std::mt19937 G;
        G g;
        const double a = .5;
        const double b = 2;
        D d;
        P p(a, b);
        const int N = 1000000;
        std::vector<D::result_type> u;
        for (int i = 0; i < N; ++i)
            u.push_back(d(g, p));
        std::sort(u.begin(), u.end());
        for (int i = 0; i < N; ++i)
            assert(std::abs(f(u[i], a, b) - double(i)/N) < .001);
    }
}
