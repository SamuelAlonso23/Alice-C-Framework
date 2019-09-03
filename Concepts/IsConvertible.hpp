//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Concepts\IsVoid.hpp>
#include <Concepts\IsArray.hpp>
#include <Concepts\IsFunction.hpp>
#include <Concepts\DeclaredValue.hpp>

namespace Alice
{
    namespace Concepts
    {
        template<class From, class To, bool = IsVoid<From> || IsArray<To> || IsFunction<To>> class IsConvertibleClass
        {
        public:
            typedef decltype(DeclaredValue<IsVoid<To>>()) Type;
        };

        template<class From, class To> class IsConvertibleClass<From, To, false>
        {
            template<typename From1> static void Check(From1){}

            template<class From1, class To1, class T = decltype(Check<To1>(DeclaredValue<From1>()))> static bool Check2(int) noexcept
            {
                return true;
            }

            template<class T, class U> static bool Check2(...) noexcept
            {
                return false;
            }
        public:
            typedef decltype(Check2<From, To>(0)) Type;
        };

        template<class From, class To> using IsConvertible = typename IsConvertibleClass<From, To>::Type;
    }
}