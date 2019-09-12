//Copyright Alice Framework, All Rights Reserved
#pragma once
#define AliceOSUnknown "This Operating System is not supported by Alice"

#if defined(_WIN32)
#define AliceWindows
#elif defined(__ANDROID__)
#define AliceAndroid
#elif defined(__linux__)
#define AliceLinux
#elif defined(__APPLE__)
#if defined(TARGET_OS_IPHONE)
#define AliceiOS
#elif defined(TARGET_OS_MAC)
#define AliceMac
#endif
#endif