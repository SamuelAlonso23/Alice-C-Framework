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
        namespace Algebra
        {
            AliceInline f32 SquareRoot(f32 a) noexcept
            {
                #if defined(AliceSse)
                #if defined(AliceFastSqrt)
                __m128 aa;
                aa[0] = a;
                return _mm_mul_ss(aa, _mm_rsqrt_ss(aa))[0];
                #else
                __m128 aa;
                aa[0] = a;
                return _mm_sqrt_ss(aa)[0];
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
                aa[0] = a;
                return _mm_sqrt_sd(aa, aa)[0];
                #else
                return static_cast<f64>(SquareRoot(static_cast<f32>(a)));
                #endif
            }
        }
    }
}