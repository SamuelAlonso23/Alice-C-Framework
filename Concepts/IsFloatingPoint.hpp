//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic/Types.hpp>

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsFloatingPointClass
        {
        public:
            constexpr static bool Value = false;
        };

        template<> class IsFloatingPointClass<f32>
        {
        public:
            constexpr static bool Value = true;
        };

        template<> class IsFloatingPointClass<f64>
        {
        public:
            constexpr static bool Value = true;
        };

        template<class T> constexpr bool IsFloatingPoint = IsFloatingPointClass<T>::Value;
    }
}