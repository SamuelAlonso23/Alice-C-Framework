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
            template<class T> AliceInline T Floor(f32 a) noexcept
            {
                return static_cast<T>(a);
            }

            template<> AliceInline f32 Floor<f32>(f32 a) noexcept
            {
                #if defined(AliceSse)
                __m128 b;
                b[0] = a;
                return _mm_cvt_si2ss(b, _mm_cvt_ss2si(b))[0];
                #else
                return static_cast<f32>(static_cast<s32>(a));
                #endif
            }

            template<> AliceInline f64 Floor<f64>(f32 a) noexcept
            {
                #if defined(AliceSse2)
                __m128 b;
                __m128d c;
                b[0] = a;
                return _mm_cvtsi64_sd(c, _mm_cvttss_si64(b))[0];
                #else
                return static_cast<f64>(static_cast<s64>(a));
                #endif
            }

            template<class T> AliceInline T Floor(f64 a) noexcept
            {
                return static_cast<T>(a);
            }

            template<> AliceInline f32 Floor<f32>(f64 a) noexcept
            {
                #if defined(AliceSse2)
                __m128d b;
                __m128 c;
                b[0] = a;
                return _mm_cvtsi64_ss(c, _mm_cvtsd_si64(b))[0];
                #else
                return static_cast<f32>(static_cast<s64>(a));
                #endif
            }

            template<> AliceInline f64 Floor<f64>(f64 a) noexcept
            {
                #if defined(AliceSse2)
                __m128d b;
                b[0] = a;
                return _mm_cvtsi64_sd(b, _mm_cvtsd_si64(b))[0];
                #else
                return static_cast<f64>(static_cast<s64>(a));
                #endif
            }
        }
    }
}