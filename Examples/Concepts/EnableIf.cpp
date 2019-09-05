#include <Basic/Types.hpp>
#include <Concepts/EnableIf.hpp>

//Return type is f32
Alice::Concepts::EnableIf<true, f32> foo()
{
    return 9.8f;
}

//Compile error, because ::Type doesn't exists
Alice::Concepts::EnableIf<false, f32> foo2()
{
    return 9.8f;
}