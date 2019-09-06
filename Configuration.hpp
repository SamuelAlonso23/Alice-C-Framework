//Copyright Alice Framework, All Rights Reserved
#pragma once
#define INCOMPATIBLE_SYSTEM "This system is not compatible with the Alice framework"

#if defined(_WIN32)
#define AliceWindows
#elif defined(__APPLE__)
#define AliceMac
//Mac OS
#elif defined(__linux__)
#define AliceLinux
#else
#error INCOMPATIBLE_SYSTEM
#endif