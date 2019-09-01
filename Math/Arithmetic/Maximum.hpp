//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic\Types.hpp>
#include <Basic\Inline.hpp>
#include <Configuration.hpp>
#if defined(AliceSse)
#include <xmmintrin.h>
#endif
#if defined(AliceSse2)
#include <emmintrin.h>
#endif

namespace Alice
{
    namespace Math
    {
        namespace Arithmetic
        {
            template<class T> AliceInline T Maximum(T a, T b) noexcept
            {
                return a > b ? a : b;
            }

            template<> AliceInline f32 Maximum<f32>(f32 a, f32 b) noexcept
            {
                #if defined(AliceSse)
                __m128 aa, bb;
                aa[0] = a;
                bb[0] = b;
                return _mm_max_ss(aa, bb)[0];
                #else
                return a > b ? a : b;
                #endif
            }

            template<> AliceInline f64 Maximum<f64>(f64 a, f64 b) noexcept
            {
                #if defined(AliceSse2)
                __m128d aa, bb;
                aa[0] = a;
                bb[0] = b;
                return _mm_max_sd(aa, bb)[0];
                #else
                return a > b ? a : b;
                #endif
            }
        }
    }
}