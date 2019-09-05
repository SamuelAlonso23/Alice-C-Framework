//Copyright Alice Framework, All Rights Reserved
#pragma once

#if defined(_WIN32)
#define AliceWindows
#elif defined(__APPLE__)
#define AliceMac
//Mac OS
#elif defined(__linux__)
#define AliceLinux
#endif