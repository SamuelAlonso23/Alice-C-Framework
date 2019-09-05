//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Database.hpp>
#include <Core/Exception.hpp>

namespace Alice
{
    namespace AppContext
    {
        AliceInline u32 GetApplicationID() noexcept
        {
            #if defined(AliceWindows)
            return GetCurrentProcessId();
            #else
            return 0;
            #endif
        }

        AliceInline void GetExecutableDirectory() noexcept
        {
            #if defined(AliceWindows)
            char path[MAX_PATH];
            if(GetModuleFileNameA(0, path, MAX_PATH) == 0)
                Alice::Exception::Raise(ExceptionType::AppPathError);
            else
                ExecutableDirectory = path;
            #endif
        }

        AliceInline void GetBaseDirectory(bool IncludeLastSeparator = true) noexcept
        {
            #if defined(AliceWindows)
            char BaseDir[MAX_PATH];
            if(GetModuleFileNameA(0, BaseDir, MAX_PATH) == 0)
                Alice::Exception::Raise(ExceptionType::AppPathError);
            else
            {
                bool Stop = false;
                s32 Index = MAX_PATH;
                char path[MAX_PATH];
                while(Index > 0)
                {
                    Index--;
                    if(!Stop)
                    {
                        if(BaseDir[Index] == '\\')
                        {
                            Stop = true;
                            if(!IncludeLastSeparator)
                                path[Index] = '\0';
                        }
                        else
                           path[Index] = '\0';
                    }
                    else
                        path[Index] = BaseDir[Index];
                }
                BaseDirectory = path;
            }
            #endif
        }
    }
}