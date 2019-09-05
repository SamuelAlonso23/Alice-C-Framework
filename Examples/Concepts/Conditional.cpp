#include <Concepts/Conditional.hpp>

constexpr bool Tester = false, Tester2 = true;

//returns int
Alice::Concepts::Conditional<Tester, float, int> ConditionalTestFalse()
{
    return 9;
}

//returns float
Alice::Concepts::Conditional<Tester2, float, int> ConditionalTestTrue()
{
    return 9.0f;
}