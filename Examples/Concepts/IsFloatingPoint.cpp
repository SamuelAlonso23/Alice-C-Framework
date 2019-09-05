#include <Concepts/IsFloatingPoint.hpp>

void FloatingPointTest()
{
    bool b = Alice::Concepts::IsFloatingPoint<f32>;//true
    b = Alice::Concepts::IsFloatingPoint<f64>;//true
    b = Alice::Concepts::IsFloatingPoint<s32>;//false
}