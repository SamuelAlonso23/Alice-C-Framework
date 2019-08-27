//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic\Types.hpp>

enum class ExceptionType : u16
{
    None,
    AppPathError,
    CpuIdNotSupported,
    IndexOverflow,
    IsReadOnly,
    OperationWithoutSuccess,
    FromIsGreaterThanTo,
    
};