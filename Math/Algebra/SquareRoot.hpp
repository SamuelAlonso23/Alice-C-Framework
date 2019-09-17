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
        namespace Algebra
        {
            AliceInline f32 SquareRoot(f32 a) noexcept
            {
                #if defined(AliceSse)
                __m128 aa;
                #if defined(AliceFastSqrt)
                #if defined(_MSC_VER)
                aa.m128_f32[0] = a;
                return _mm_mul_ss(aa, _mm_rsqrt_ss(aa)).m128_f32[0];
                #else
                aa[0] = a;
                return _mm_mul_ss(aa, _mm_rsqrt_ss(aa))[0];
                #endif
                #else
                #if defined(_MSC_VER)
                aa.m128_f32[0] = a;
                return _mm_sqrt_ss(aa).m128_f32[0];
                #else
                aa[0] = a;
                return _mm_sqrt_ss(aa)[0];
                #endif
                #endif
                #else
                union
                {
                    s32 i;
                    f32 x;
                } u;
                u.x = a;
                u.i = (1 << 29) + (u.i >> 1) - (1 << 22); 
                u.x = u.x + a /u.x;
                u.x = 0.25f * u.x + a / u.x;
                return u.x;
                #endif
            }

            AliceInline f64 SquareRoot(f64 a) noexcept
            {
                #if defined(AliceSse2)
                __m128d aa;
                #if defined(_MSC_VER)
                aa.m128d_f64[0] = a;
                return _mm_sqrt_sd(aa, aa).m128d_f64[0];
                #else
                aa[0] = a;
                return _mm_sqrt_sd(aa, aa)[0];
                #endif
                #else
                return static_cast<f64>(SquareRoot(static_cast<f32>(a)));
                #endif
            }
        }
    }
}