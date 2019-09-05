#include <Concepts/AddConstVolatile.hpp>

bool Tester = true;

//returns const volatile bool
Alice::Concepts::AddConstVolatile<decltype(Tester)> AddConstVolatileTest()
{
    return true;
}