//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Database.hpp>
#include <Core/Exception.hpp>

namespace Alice
{ 
    class App
    {
    public:
        AliceInline App() noexcept
        {
            if(AppLoaded)
                Exception::Raise(ExceptionType::AppAlreadyLoaded);
            else
            {
                AppLoaded = true;

            }
        }

        AliceInline ~App() noexcept
        {

        }
    };
}