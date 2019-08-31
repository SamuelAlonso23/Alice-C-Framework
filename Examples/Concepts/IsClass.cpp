#include <Concepts\IsClass.hpp>

class Class{};
enum Enum{};

void IsClassTest()
{
    bool b = Alice::Concepts::IsClass<Class>;//true
    b = Alice::Concepts::IsClass<Enum>;//false
}