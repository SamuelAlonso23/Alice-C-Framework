#include <iostream>
#define AliceSse
#include <Math\Algebra\Floor.hpp>

void FloorTest()
{
    std::cout << Alice::Math::Algebra::Floor<f32>(3.8f) << std::endl;//outputs 3
    char a;
    std::cin >> a;
}