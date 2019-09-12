//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Database.hpp>
#include <Core/Exception.hpp>

namespace Alice
{
    namespace MainWindow
    {
        AliceInline void Resize(u16 Width, u16 Height) noexcept
        {
            #if defined(AliceWindows)
            if(!SetWindowPos(MainWindowHandler, 0, 0, 0, Width, Height, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER))
                Exception::Raise(ExceptionType::MainWindowResizeFailed);
            else
            {
                MainWindowWidth = Width;
                MainWindowHeight = Height;
            }
            #endif
        }

        AliceInline void Relocate(u16 X, u16 Y) noexcept
        {
            #if defined(AliceWindows)
            if(!SetWindowPos(MainWindowHandler, 0, X, Y, 0, 0, SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER))
                Exception::Raise(ExceptionType::MainWindowRelocationFailed);
            else
            {
                MainWindowX = X;
                MainWindowY = Y;
            }
            #endif
        }
    }
}

#include <Basic/NoDefault.hpp>
#include <Engine/Behaviour.hpp>

namespace Alice
{
    namespace MainWindow
    {
        #if defined(AliceWindows)
        AliceInline LRESULT CALLBACK Message(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) noexcept
        {
            switch(msg)
            {
                default: AliceNoDefault
                case WM_KEYDOWN:
                    if(wp == 0x08)
                         Exit = true;
                break;
            }
            return DefWindowProcW(hwnd, msg, wp, lp);
        }
        #endif

        AliceInline void Init() noexcept
        {
            if(AppLoaded)
                Exception::Raise(ExceptionType::MainWindowAlreadyLoaded);
            else
            {
                AppLoaded = true;
                #if defined(AliceWindows)
                Engine::Behaviour::Awake();
                WNDCLASSEXW wndc = {0};
                wndc.cbClsExtra = 0;
                wndc.cbSize = sizeof(wndc);
                wndc.cbWndExtra = 0;
                wndc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
                wndc.hCursor = LoadCursor(0, IDC_ARROW);
                wndc.hIcon = 0;
                wndc.hIconSm = 0;
                wndc.hInstance = AppInstance;
                wndc.lpfnWndProc = Message;
                wndc.lpszClassName = MainWindowTitle;
                wndc.lpszMenuName = 0;
                wndc.style = CS_OWNDC;
                if(!RegisterClassExW(&wndc))
                    Exception::Raise(ExceptionType::MainWindowCannotBeRegistered);
                else
                {
                    MainWindowHandler = CreateWindowExW(0, MainWindowTitle, 0, WS_EX_APPWINDOW, MainWindowX, MainWindowY, MainWindowWidth, MainWindowHeight, 0, 0, AppInstance, 0);
                    if(!MainWindowHandler || !SetWindowLongPtrW(MainWindowHandler, GWL_STYLE, 0))
                        Exception::Raise(ExceptionType::MainWindowCannotBeCreated);
                    else
                    {
                        ShowWindow(MainWindowHandler, SW_SHOW);
                        Engine::Behaviour::Start();
                        MSG msg = {0};
                        while(!Exit)
                        {
                            Engine::Behaviour::Update();
                            GetMessageW(&msg, MainWindowHandler, 0, 0);
                            TranslateMessage(&msg);
                            DispatchMessageW(&msg);
                        }
                        Engine::Behaviour::Finish();
                    }
                }
                #endif
            }
        }

        AliceInline void End() noexcept
        {
            #if defined(AliceWindows)
            if(!DestroyWindow(MainWindowHandler))
                Exception::Raise(ExceptionType::MainWindowDestroyFailed);
            else
            {
                if(!UnregisterClassW(MainWindowTitle, AppInstance))
                    Exception::Raise(ExceptionType::MainWindowUnregistrationFailed);
                else
                {
                    DWORD id = 0;
                    if(GetExitCodeProcess(AppInstance, &id))
                        if(id)
                        {
                            ExitProcess(id);
                            TerminateProcess(AppInstance, id);
                        }
                    Exception::Raise(ExceptionType::AppCouldNotTerminate);
                }
            }
            #endif
        }
    }
}