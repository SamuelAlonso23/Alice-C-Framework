#include <Concepts/AddPointer.hpp>

bool Tester = true;

//modify parameter b of type bool*
void AddPointerTest(Alice::Concepts::AddPointer<decltype(Tester)> b)
{
    *b = true;
}