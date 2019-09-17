//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic/Types.hpp>
#include <Basic/Inline.hpp>
#include <Configuration.hpp>
#if defined(AliceSse)
#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <xmmintrin.h>
#endif
#endif
#if defined(AliceSse2)
#if defined(_MSC_VER)
#if !defined(AliceSse)
#include <intrin.h>
#endif
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
            template<class T> AliceInline T Minimum(T a, T b) noexcept
            {
                return a < b ? a : b;
            }

            template<> AliceInline f32 Minimum<f32>(f32 a, f32 b) noexcept
            {
                #if defined(AliceSse)
                __m128 aa, bb;
                #if defined(_MSC_VER)
                aa.m128_f32[0] = a;
                bb.m128_f32[0] = b;
                return _mm_min_ss(aa, bb).m128_f32[0];
                #else
                aa[0] = a;
                bb[0] = b;
                return _mm_min_ss(aa, bb)[0];
                #endif
                #else
                return a < b ? a : b;
                #endif
            }

            template<> AliceInline f64 Minimum<f64>(f64 a, f64 b) noexcept
            {
                #if defined(AliceSse2)
                __m128d aa, bb;
                #if defined(_MSC_VER)
                aa.m128d_f64[0] = a;
                bb.m128d_f64[0] = b;
                return _mm_min_sd(aa, bb).m128d_f64[0];
                #else
                aa[0] = a;
                bb[0] = b;
                return _mm_min_sd(aa, bb)[0];
                #endif
                #else
                return a < b ? a : b;
                #endif
            }
        }
    }
}