//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Database.hpp>
#include <Core/Exception.hpp>
#include <Basic/NoDefault.hpp>
#include <Engine/Behaviour.hpp>

namespace Alice
{
    namespace UI
    {
        class Window
        {
        private:
            u16 x = 0, y = 0, width = 0, height = 0;

            #if defined(AliceWindows)
            LPCWSTR windowName = 0;

            HWND WindowHandler = 0;

            AliceInline static LRESULT CALLBACK Message(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) noexcept
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
        public:
            AliceInline Window(/*Engine::Behaviour* Behaviour, */const char* WindowName, u16 X, u16 Y, u16 Width, u16 Height) noexcept
            {
                #if defined(AliceWindows)
                s32 wnsize = MultiByteToWideChar(CP_ACP, 0, WindowName, -1, 0, 0);
                windowName = new WCHAR[wnsize];
                MultiByteToWideChar(CP_ACP, 0, WindowName, -1, (LPWSTR)windowName, wnsize);
                //Behaviour->Awake();
                WNDCLASSEXW wnd = {0};
                wnd.cbClsExtra = 0;
                wnd.cbSize = sizeof(wnd);
                wnd.cbWndExtra = 0;
                wnd.hbrBackground = 0;
                wnd.hCursor = LoadCursor(0, IDC_ARROW);
                wnd.hIcon = 0;
                wnd.hIconSm = 0;
                wnd.hInstance = AppInstance;
                wnd.lpfnWndProc = Message;
                wnd.lpszClassName = windowName;
                wnd.lpszMenuName = 0;
                wnd.style = CS_OWNDC;
                if(RegisterClassExW(&wnd))
                {
                    WindowHandler = CreateWindowExW(0, windowName, L"", WS_EX_APPWINDOW, X, Y, Width, Height, 0, 0, AppInstance, 0);
                    if(WindowHandler)
                    {
                        x = X;
                        y = Y;
                        width = Width;
                        height = Height;
                        ShowWindow(WindowHandler, SW_SHOW);
                        //Behaviour->Start();
                        MSG msg = {0};
                        while(!Exit)
                        {
                            GetMessageW(&msg, WindowHandler, 0, 0);
                            TranslateMessage(&msg);
                            DispatchMessageW(&msg);
                            //Behaviour->Update();
                        }
                        //Behaviour->Finish();
                    }
                    else
                        Exception::Raise(ExceptionType::WindowCreationFailed);
                }
                else
                    Exception::Raise(ExceptionType::WindowRegistrationFailed);
                #endif
            }

            AliceInline ~Window() noexcept
            {
                #if defined(AliceWindows)
                if(DestroyWindow(WindowHandler))
                {
                    if(!UnregisterClassW(windowName, AppInstance))
                        Exception::Raise(ExceptionType::WindowUnregistrationFailed);
                    else
                        delete[] windowName;
                }
                else
                    Exception::Raise(ExceptionType::WindowDestroyFailed);
                #endif
            }

            #if defined(AliceWindows)
            AliceInline HWND WindowHandle() const noexcept
            {
                return WindowHandler;
            }
            #endif

            AliceInline u16 X() const noexcept
            {
                return x;
            }

            AliceInline u16 Y() const noexcept
            {
                return y;
            }

            AliceInline u16 Width() const noexcept
            {
                return width;
            }

            AliceInline u16 Height() const noexcept
            {
                return height;
            }

            AliceInline void Relocate(u16 X, u16 Y) noexcept
            {
                #if defined(AliceWindows)
                if(!SetWindowPos(WindowHandler, 0, X, Y, 0, 0, SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER))
                    Exception::Raise(ExceptionType::WindowRelocationFailed);
                else
                {
                    x = X;
                    y = Y;
                }
                #endif
            }

            AliceInline void Resize(u16 Width, u16 Height) noexcept
            {
                #if defined(AliceWindows)
                if(!SetWindowPos(WindowHandler, 0, 0, 0, Width, Height, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER))
                    Exception::Raise(ExceptionType::WindowResizeFailed);
                else
                {
                    width = Width;
                    height = Height;
                }
                #endif
            }
        };
    }
}