//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <unordered_set>

// template <class Value, class Hash = hash<Value>, class Pred = equal_to<Value>,
//           class Alloc = allocator<Value>>
// class unordered_set
// {
// public:
//     // types
//     typedef Value                                                      value_type;
//     typedef value_type                                                 key_type;
//     typedef Hash                                                       hasher;
//     typedef Pred                                                       key_equal;
//     typedef Alloc                                                      allocator_type;
//     typedef value_type&                                                reference;
//     typedef const value_type&                                          const_reference;
//     typedef typename allocator_traits<allocator_type>::pointer         pointer;
//     typedef typename allocator_traits<allocator_type>::const_pointer   const_pointer;
//     typedef typename allocator_traits<allocator_type>::size_type       size_type;
//     typedef typename allocator_traits<allocator_type>::difference_type difference_type;

#include <unordered_set>
#include <type_traits>

int main()
{
    {
        typedef std::unordered_set<short> C;
        static_assert((std::is_same<C::value_type, short>::value), "");
        static_assert((std::is_same<C::key_type, short>::value), "");
        static_assert((std::is_same<C::hasher, std::hash<C::key_type> >::value), "");
        static_assert((std::is_same<C::key_equal, std::equal_to<C::key_type> >::value), "");
        static_assert((std::is_same<C::allocator_type, std::allocator<C::value_type> >::value), "");
        static_assert((std::is_same<C::reference, C::value_type&>::value), "");
        static_assert((std::is_same<C::const_reference, const C::value_type&>::value), "");
        static_assert((std::is_same<C::pointer, C::value_type*>::value), "");
        static_assert((std::is_same<C::const_pointer, const C::value_type*>::value), "");
        static_assert((std::is_same<C::size_type, std::size_t>::value), "");
        static_assert((std::is_same<C::difference_type, std::ptrdiff_t>::value), "");
    }
}
