#include <Concepts/AddLvalueReference.hpp>

bool Tester = true;

//returns bool&
Alice::Concepts::AddLvalueReference<decltype(Tester)> AddLvalueReferenceTest()
{
    bool b = true;
    return b;
}