#include <iostream>
#define AliceSse
#include <Math/Algebra/Round.hpp>

void RoundTest()
{
    std::cout << Alice::Math::Algebra::Round<f32>(3.3f) << std::endl; //outputs 3
    std::cout << Alice::Math::Algebra::Round<f32>(3.8f) << std::endl;//outputs 4
    char a;
    std::cin >> a;
}