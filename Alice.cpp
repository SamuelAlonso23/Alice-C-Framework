//Copyright Alice Framework, All Rights Reserved
#include <Database.hpp>
#include <Core/App.hpp>

#if defined(AliceWindows)
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    AppInstance = hInstance;
    Alice::App::Init();
}
#elif defined(AliceMac)
//Mac OS
#elif defined(AliceLinux)
int main(const int argc, const char ** argv)
{
    return 0;
}
#else
#error INCOMPATIBLE_SYSTEM
#endif