#include <Concepts\IsConvertible.hpp>

void IsConvertibleTest()
{
    f32 a = 7.6f;
    Alice::Concepts::IsConvertible<decltype(a), f64> b = 8;//b type is f64
}