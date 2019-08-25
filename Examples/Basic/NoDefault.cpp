#include <Basic/Types.hpp>
#include <Basic/NoDefault.hpp>

void foo(s32 int1)
{
    switch(int1)
    {
        default:
            AliceNoDefault
        case 1:
            return;
    }
}