//Copyright Alice Framework, All Rights Reserved

/** @file Inline.hpp */
#pragma once

#if defined(_MSC_VER)
#define AliceInline __forceinline
#else
#define AliceInline inline __attribute__((always_inline))
#endif