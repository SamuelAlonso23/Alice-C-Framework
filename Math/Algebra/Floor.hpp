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
            template <class T> AliceInline T Floor(f32 a) noexcept
            {
                return static_cast<T>(a);
            }

            template<> AliceInline f32 Floor<f32>(f32 a) noexcept
            {
                #if defined(AliceSse)
                __m128 b;
                #if defined(_MSC_VER)
                b.m128_f32[0] = a;
                return _mm_cvt_si2ss(b, _mm_cvt_ss2si(b)).m128_f32[0];
                #else
                b[0] = a;
                return _mm_cvt_si2ss(b, _mm_cvt_ss2si(b))[0];
                #endif
                #else
                return static_cast<f32>(static_cast<s32>(a));
                #endif
            }

            template<> AliceInline f64 Floor<f64>(f32 a) noexcept
            {
                #if defined(AliceSse2)
                __m128 b;
                __m128d c;
                #if defined(_MSC_VER)
                b.m128_f32[0] = a;
                return _mm_cvtsi64_sd(c, _mm_cvttss_si64(b)).m128d_f64[0];
                #else
                b[0] = a;
                return _mm_cvtsi64_sd(c, _mm_cvttss_si64(b))[0];
                #endif
                #else
                return static_cast<f64>(static_cast<s64>(a));
                #endif
            }

            template <class T> AliceInline T Floor(f64 a) noexcept
            {
                return static_cast<T>(a);
            }

            template<> AliceInline f32 Floor<f32>(f64 a) noexcept
            {
                #if defined(AliceSse2)
                __m128d b;
                __m128 c;
                #if defined(_MSC_VER)
                b.m128d_f64[0] = a;
                return _mm_cvt_si2ss(c, _mm_cvtsd_si64(b)).m128_f32[0];
                #else
                b[0] = a;
                return _mm_cvt_si2ss(c, _mm_cvtsd_si64(b))[0];
                #endif
                #else
                return static_cast<f32>(static_cast<s64>(a));
                #endif
            }

            template<> AliceInline f64 Floor<f64>(f64 a) noexcept
            {
                #if defined(AliceSse2)
                __m128d b;
                #if defined(_MSC_VER)
                b.m128d_f64[0] = a;
                return _mm_cvtsi64_sd(b, _mm_cvtsd_si64(b)).m128d_f64[0];
                #else
                b[0] = a;
                return _mm_cvtsi64_sd(b, _mm_cvtsd_si64(b))[0];
                #endif
                #else
                return static_cast<f64>(static_cast<s64>(a));
                #endif
            }
        }
    }
}