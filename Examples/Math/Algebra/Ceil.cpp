#include <iostream>
#define AliceSse
#include <Math/Algebra/Ceil.hpp>

void CeilTest()
{
    std::cout << Alice::Math::Algebra::Ceil<f32>(3.8f) << std::endl;//outputs 4
    char a;
    std::cin >> a;
}