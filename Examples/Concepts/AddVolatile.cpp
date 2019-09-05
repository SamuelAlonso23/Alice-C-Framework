#include <Concepts/AddVolatile.hpp>

bool Tester = true;

//returns volatile bool
Alice::Concepts::AddVolatile<decltype(Tester)> AddVolatileTest()
{
    return true;
}