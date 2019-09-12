//Copyright Alice Framework, All Rights Reserved
#include <Core/MainWindow.hpp>

#if defined(AliceWindows)
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    FreeConsole();
    AppInstance = hInstance;
    Alice::MainWindow::Init();
    Alice::MainWindow::End();
}

#endif