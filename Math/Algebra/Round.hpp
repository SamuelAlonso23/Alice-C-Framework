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
            template<class T> AliceInline T Round(f32 a) noexcept
            {
                return static_cast<T>(a + 0.5f);
            }

            template<> AliceInline f32 Round<f32>(f32 a) noexcept
            {
                #if defined(AliceSse)
                __m128 b, c;
                #if defined(_MSC_VER)
                b.m128_f32[0] = a;
                c.m128_f32[0] = 0.5f;
                return _mm_cvt_si2ss(b, _mm_cvt_ss2si(_mm_add_ss(b, c))).m128_f32[0];
                #else
                b[0] = a;
                c[0] = 0.5f;
                return _mm_cvt_si2ss(b, _mm_cvt_ss2si(_mm_add_ss(b, c)))[0];
                #endif
                #else
                return static_cast<f32>(static_cast<s32>(a + 0.5f));
                #endif
            }

            template<> AliceInline f64 Round<f64>(f32 a) noexcept
            {
                #if defined(AliceSse2)
                __m128 b, c;
                __m128d d;
                #if defined(_MSC_VER)
                b.m128_f32[0] = a;
                c.m128_f32[0] = 0.5f;
                return _mm_cvtsi64_sd(d, _mm_cvttss_si64(_mm_add_ss(b, c))).m128d_f64[0];
                #else
                b[0] = a;
                c[0] = 0.5f;
                return _mm_cvtsi64_sd(d, _mm_cvttss_si64(_mm_add_ss(b, c)))[0];
                #endif
                #else
                return static_cast<f64>(static_cast<s64>(a + 0.5f));
                #endif
            }

            template<class T> AliceInline T Round(f64 a) noexcept
            {
                return static_cast<T>(static_cast<s64>(a + 0.5));
            }

            template<> AliceInline f32 Round<f32>(f64 a) noexcept
            {
                #if defined(AliceSse2)
                __m128d b, c;
                __m128 d;
                #if defined(_MSC_VER)
                b.m128d_f64[0] = a;
                c.m128d_f64[0] = 0.5;
                return _mm_cvtsi64_ss(d, _mm_cvtsd_si64(_mm_add_sd(b, c))).m128_f32[0];
                #else
                b[0] = a;
                c[0] = 0.5;
                return _mm_cvtsi64_ss(d, _mm_cvtsd_si64(_mm_add_sd(b, c)))[0];
                #endif
                #else
                return static_cast<f32>(static_cast<s64>(a + 0.5));
                #endif
            }

            template<> AliceInline f64 Round<f64>(f64 a) noexcept
            {
                #if defined(AliceSse2)
                __m128d b, c;
                #if defined(_MSC_VER)
                b.m128d_f64[0] = a;
                c.m128d_f64[0] = 0.5;
                return _mm_cvtsi64_sd(b, _mm_cvtsd_si64(_mm_add_sd(b, c))).m128d_f64[0];
                #else
                b[0] = a;
                c[0] = 0.5;
                return _mm_cvtsi64_sd(b, _mm_cvtsd_si64(_mm_add_sd(b, c)))[0];
                #endif
                #else
                return static_cast<f64>(static_cast<s64>(a + 0.5));
                #endif
            }
        }
    }
}