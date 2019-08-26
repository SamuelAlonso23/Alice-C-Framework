//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <OS.hpp>

const char* BaseDirectory = nullptr;
const char* ExecutableDirectory = nullptr;

#if defined(AliceWindows)
HINSTANCE AppInstance = nullptr;
#endif