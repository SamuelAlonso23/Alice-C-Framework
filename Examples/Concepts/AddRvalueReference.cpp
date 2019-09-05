#include <Concepts/AddRvalueReference.hpp>

bool Tester = true;

//returns bool&&
Alice::Concepts::AddRvalueReference<decltype(Tester)> AddRvalueReferenceTest()
{
    return true;
}