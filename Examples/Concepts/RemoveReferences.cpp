#include <Basic/Types.hpp>
#include <Concepts/RemoveReferences.hpp>

//No reference, return type is f32
Alice::Concepts::RemoveReferences<f32> foo()
{
    return 9.7f;
}

//l-value reference, return type is f32
Alice::Concepts::RemoveReferences<f32&> foo2()
{
    return 0.3f;
}

//r-value reference, return type is f32
Alice::Concepts::RemoveReferences<f32&&> foo3()
{
    return 0.2f;
}