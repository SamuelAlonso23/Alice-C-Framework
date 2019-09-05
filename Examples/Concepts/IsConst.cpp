#include <Basic/Types.hpp>
#include <Concepts/IsConst.hpp>

//returns true
bool foo()
{
    const f32 float1 = 98.1f;
    return Alice::Concepts::IsConst<decltype(float1)>;
}

//returns false
bool foo2()
{
    f32 float1 = 98.1f;
    return Alice::Concepts::IsConst<decltype(float1)>;
}