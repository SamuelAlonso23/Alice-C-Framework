#include <Basic/Types.hpp>
#include <Concepts/IsSame.hpp>

//returns true
bool foo(s32 int1, s32 int2)
{
    return Alice::Concepts::IsSame<decltype(int1), decltype(int2)>;
}

//returns false
bool foo(s32 int1, f32 float1)
{
    return Alice::Concepts::IsSame<decltype(int1), decltype(float1)>;
}