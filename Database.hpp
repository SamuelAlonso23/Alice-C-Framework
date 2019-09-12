//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <OS.hpp>

bool AppLoaded = false, Exit = false;

u16 MainWindowX = 0, MainWindowY = 0, MainWindowWidth = 100, MainWindowHeight = 100;

const char* BaseDirectory = nullptr;

const char* ExecutableDirectory = nullptr;

#if defined(AliceWindows)
LPCWSTR MainWindowTitle = L"AliceMainWindow";

HINSTANCE AppInstance = nullptr;

HWND MainWindowHandler = nullptr;
#endif