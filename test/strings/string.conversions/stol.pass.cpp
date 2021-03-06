//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// long stol(const string& str, size_t *idx = 0, int base = 10);
// long stol(const wstring& str, size_t *idx = 0, int base = 10);

#include <string>
#include <cassert>

int main()
{
    assert(std::stol("0") == 0);
    assert(std::stol(L"0") == 0);
    assert(std::stol("-0") == 0);
    assert(std::stol(L"-0") == 0);
    assert(std::stol("-10") == -10);
    assert(std::stol(L"-10") == -10);
    assert(std::stol(" 10") == 10);
    assert(std::stol(L" 10") == 10);
    size_t idx = 0;
    assert(std::stol("10g", &idx, 16) == 16);
    assert(idx == 2);
    idx = 0;
    assert(std::stol(L"10g", &idx, 16) == 16);
    assert(idx == 2);
    idx = 0;
    try
    {
        std::stol("", &idx);
        assert(false);
    }
    catch (const std::invalid_argument&)
    {
        assert(idx == 0);
    }
    try
    {
        std::stol(L"", &idx);
        assert(false);
    }
    catch (const std::invalid_argument&)
    {
        assert(idx == 0);
    }
    try
    {
        std::stol("  - 8", &idx);
        assert(false);
    }
    catch (const std::invalid_argument&)
    {
        assert(idx == 0);
    }
    try
    {
        std::stol(L"  - 8", &idx);
        assert(false);
    }
    catch (const std::invalid_argument&)
    {
        assert(idx == 0);
    }
    try
    {
        std::stol("a1", &idx);
        assert(false);
    }
    catch (const std::invalid_argument&)
    {
        assert(idx == 0);
    }
    try
    {
        std::stol(L"a1", &idx);
        assert(false);
    }
    catch (const std::invalid_argument&)
    {
        assert(idx == 0);
    }
}
