//Copyright Alice Framework, All Rights Reserved
#pragma once

/** @file NoDefault.hpp */

#if defined(_MSC_VER)
#define AliceNoDefault __assume(0);
#else
#define AliceNoDefault __builtin_unreachable();
#endif