//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic/Inline.hpp>
#include <Configuration.hpp>
#include <Basic/ExceptionType.hpp>

namespace Alice
{
    ExceptionType AliceException = ExceptionType::None;

    namespace Exception
    {
        AliceInline void Raise(const ExceptionType&& ExceptionToRaise, ExceptionType& ExceptionToBeRaised = AliceException) noexcept
        {
            #ifndef AliceUnsafe
            #if defined(AliceExceptionsOnlyOnDebug)
            #if defined(AliceDebug)
            ExceptionToBeRaised = ExceptionToRaise;
            #endif
            #else
            ExceptionToBeRaised = ExceptionToRaise;
            #endif
            #endif
        }

        AliceInline bool Check(const ExceptionType&& ExceptionToCheck, const ExceptionType ExceptionToBeChecked = AliceException) noexcept
        {
            #ifndef AliceUnsafe
            #if defined(AliceExceptionsOnlyOnDebug)
            #if defined(AliceDebug)
            return ExceptionToCheck == ExceptionToBeChecked ? true : false;
            #else
            return false;
            #endif
            #else
            return ExceptionToCheck == ExceptionToBeChecked ? true : false;
            #endif
            #else
            return false;
            #endif
        }

        AliceInline bool CheckAndReset(const ExceptionType&& ExceptionToCheck, ExceptionType& ExceptionToBeChecked = AliceException) noexcept
        {
            #ifndef AliceUnsafe
            #if defined(AliceExceptionsOnlyOnDebug)
            #if defined(AliceDebug)
            bool ret = ExceptionToCheck == ExceptionToBeChecked ? true : false;
            if(ret)
                ExceptionToBeChecked = ExceptionType::None;
            return ret;
            #else
            return false;
            #endif
            #else
            bool ret = ExceptionToCheck == ExceptionToBeChecked ? true : false;
            if(ret)
                ExceptionToBeChecked = ExceptionType::None;
            return ret;
            #endif
            #else
            return false;
            #endif
        }
    }
}