//Copyright Alice Framework, All Rights Reserved
#pragma once

#if defined(_MSC_VER)
#define AliceInline __forceinline
#else
#define AliceInline inline __attribute__((always_inline))
#endif