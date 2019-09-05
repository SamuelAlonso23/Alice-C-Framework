#include <Concepts/DeclaredValue.hpp>

void DeclaredValueTest()
{
    constexpr bool b = true;
    decltype(Alice::Concepts::DeclaredValue<decltype(b)>()) bb = true; //bb type is const bool&&
}