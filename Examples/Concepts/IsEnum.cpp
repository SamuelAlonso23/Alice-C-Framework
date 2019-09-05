#include <Concepts/IsEnum.hpp>

class Class{};
enum Enum{};
enum class EnumClass{};

void IsEnumTest()
{
    bool b = Alice::Concepts::IsEnum<Class>;//false
    b = Alice::Concepts::IsEnum<Enum>;//true
    b = Alice::Concepts::IsEnum<EnumClass>;//true
}