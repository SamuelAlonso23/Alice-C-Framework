//Copyright Alice Framework, All Rights Reserved
#include <Database.hpp>
#include <Core\App.hpp>

#if defined(AliceWindows)
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    AppInstance = hInstance;
    Alice::App::Init();
}
#endif