//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic/Types.hpp>
#include <Basic/Inline.hpp>
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
            template<class T> AliceInline T Ceil(f32 a) noexcept
            {
                return static_cast<T>(a + 1.0f);
            }

            template<> AliceInline f32 Ceil<f32>(f32 a) noexcept
            {
                #if defined(AliceSse)
                __m128 b, c;
                b[0] = a;
                c[0] = 1.0f;
                return _mm_cvt_si2ss(b, _mm_cvt_ss2si(_mm_add_ss(b, c)))[0];
                #else
                return static_cast<f32>(static_cast<s32>(a + 1.0f));
                #endif
            }

            template<> AliceInline f64 Ceil<f64>(f32 a) noexcept
            {
                #if defined(AliceSse2)
                __m128 b, c;
                __m128d d;
                b[0] = a;
                c[0] = 1.0f;
                return _mm_cvtsi64_sd(d, _mm_cvttss_si64(_mm_add_ss(b, c)))[0];
                #else
                return static_cast<f64>(static_cast<s64>(a + 1.0f));
                #endif
            }

            template<class T> AliceInline T Ceil(f64 a) noexcept
            {
                return static_cast<T>(static_cast<s64>(a + 1.0));
            }

            template<> AliceInline f32 Ceil<f32>(f64 a) noexcept
            {
                #if defined(AliceSse2)
                __m128d b, c;
                __m128 d;
                b[0] = a;
                c[0] = 1.0;
                return _mm_cvtsi64_ss(d, _mm_cvtsd_si64(_mm_add_sd(b, c)))[0];
                #else
                return static_cast<f32>(static_cast<s64>(a + 1.0));
                #endif
            }

            template<> AliceInline f64 Ceil<f64>(f64 a) noexcept
            {
                #if defined(AliceSse2)
                __m128d b, c;
                b[0] = a;
                c[0] = 1.0;
                return _mm_cvtsi64_sd(b, _mm_cvtsd_si64(_mm_add_sd(b, c)))[0];
                #else
                return static_cast<f64>(static_cast<s64>(a + 1.0));
                #endif
            }
        }
    }
}