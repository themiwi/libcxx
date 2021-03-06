//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <functional>

// result_of<Fn(ArgTypes...)>

#include <type_traits>
#include <memory>

typedef bool (&PF1)();
typedef short (*PF2)(long);

struct S
{
    operator PF2() const;
    double operator()(char, int&);
    void calc(long) const;
    char data_;
};

typedef void (S::*PMS)(long) const;
typedef char S::*PMD;

int main()
{
    static_assert((std::is_same<std::result_of<S(int)>::type, short>::value), "Error!");
    static_assert((std::is_same<std::result_of<S&(unsigned char, int&)>::type, double>::value), "Error!");
    static_assert((std::is_same<std::result_of<PF1()>::type, bool>::value), "Error!");
//     static_assert(std::is_same<std::result_of<PMS(std::unique_ptr<S>, int)>::type, void>::value, "Error!");
//     static_assert(std::is_same<std::result_of<PMD(S)>::type, char&&>::value, "Error!");
//     static_assert(std::is_same<std::result_of<PMD(const S*)>::type, const char&>::value, "Error!");
}
