//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic\Epsilon.hpp>
#include <Basic\Inline.hpp>
#include <Configuration.hpp>
#if defined(AliceSse)
f32 AliceAbsoluteValueZero = 0;
#include <xmmintrin.h>
#endif
#if defined(AliceSse2)
f64 AliceAbsoluteValueZero64 = 0;
#include <emmintrin.h>
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
                #if defined(AliceSse)
                __m128 aa, bb;
                aa[0] = a;
                bb[0] = -Epsilon32;
                if(_mm_comile_ss(aa, bb))
                {
                    bb[0] = AliceAbsoluteValueZero;
                    return _mm_xor_ps(aa, bb)[0];
                }
                else
                    return a;
                #else
                return a <= -Epsilon32 ? -a : a;
                #endif
            }

            template<> AliceInline f64 AbsoluteValue<f64>(f64 a) noexcept
            {
                #if defined(AliceSse2)
                __m128d aa, bb;
                aa[0] = a;
                bb[0] = -Epsilon64;
                if(_mm_comile_sd(aa, bb))
                {
                    bb[0] = AliceAbsoluteValueZero64;
                    return _mm_xor_pd(aa, bb)[0];
                }
                else
                    return a;
                #else
                return a <= -Epsilon64 ? -a : a;
                #endif
            }
        }
    }
}