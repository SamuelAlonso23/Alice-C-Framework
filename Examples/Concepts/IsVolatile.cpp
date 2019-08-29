#include <Basic/Types.hpp>
#include <Concepts\IsVolatile.hpp>

//returns true
bool foo()
{
    volatile f32 float1 = 98.1f;
    return Alice::Concepts::IsVolatile<decltype(float1)>;
}

//returns false
bool foo2()
{
    f32 float1 = 98.1f;
    return Alice::Concepts::IsVolatile<decltype(float1)>;
}