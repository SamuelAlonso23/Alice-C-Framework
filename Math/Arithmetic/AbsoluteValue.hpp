//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic/Epsilon.hpp>
#include <Basic/Inline.hpp>
#include <Configuration.hpp>
#if defined(AliceSse2)
#if defined (_MSC_VER)
#include <intrin.h>
#else
#include <emmintrin.h>
#endif
#endif

namespace Alice
{
    namespace Math
    {
        namespace Arithmetic
        {
            template<class T> AliceInline T AbsoluteValue(T a) noexcept
            {
                return a < 0 ? -a : a;
            }

            template<> AliceInline f32 AbsoluteValue<f32>(f32 a) noexcept
            {
                #if defined(AliceSse2)
                const __m128 b = _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff));
                __m128 aa;
                #if defined(_MSC_VER)
                aa.m128_f32[0] = a;
                return _mm_and_ps(aa, b).m128_f32[0];
                #else
                aa[0] = a;
                return _mm_and_ps(aa, b)[0];
                #endif
                #else
                return a <= -Epsilon32 ? -a : a;
                #endif
            }

            template<> AliceInline f64 AbsoluteValue<f64>(f64 a) noexcept
            {
                #if defined(AliceSse2)
                const __m128d b = _mm_castsi128_pd(_mm_set1_epi64x(0x7fffffffffffffff));
                __m128d aa;
                #if defined(_MSC_VER)
                aa.m128d_f64[0] = a;
                return _mm_and_pd(aa, b).m128d_f64[0];
                #else
                aa[0] = a;
                return _mm_and_pd(aa, b)[0];
                #endif
                #else
                return a <= -Epsilon64 ? -a : a;
                #endif
            }
        }
    }
}