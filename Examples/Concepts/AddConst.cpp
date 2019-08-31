#include <Concepts\AddConst.hpp>

bool Tester = true;

//returns const bool
Alice::Concepts::AddConst<decltype(Tester)> AddConstTest()
{
    return true;
}