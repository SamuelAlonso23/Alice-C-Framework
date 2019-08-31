#include <Concepts\IsUnion.hpp>

class Class{};
union Union{};

void IsUnionTest()
{
    bool b = Alice::Concepts::IsUnion<Class>;//false
    b = Alice::Concepts::IsUnion<Union>;//true
}