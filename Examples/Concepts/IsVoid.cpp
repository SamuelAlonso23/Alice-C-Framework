#include <Concepts\IsVoid.hpp>

volatile const void Tester;
const void Tester2;
volatile void Tester3;
void Tester4;

void VoidTest()
{
    bool b = Alice::Concepts::IsVoid<decltype(Tester)>;//true
    b = Alice::Concepts::IsVoid<decltype(Tester2)>;//true
    b = Alice::Concepts::IsVoid<decltype(Tester3)>;//true
    b = Alice::Concepts::IsVoid<decltype(Tester4)>;//true
}

void ConstVoidTest()
{
    bool b = Alice::Concepts::IsConstVoid<decltype(Tester)>;//false
    b = Alice::Concepts::IsConstVoid<decltype(Tester2)>;//true
    b = Alice::Concepts::IsConstVoid<decltype(Tester3)>;//false
    b = Alice::Concepts::IsConstVoid<decltype(Tester4)>;//true
}

void VolatileVoidTest()
{
    bool b = Alice::Concepts::IsVolatileVoid<decltype(Tester)>;//false
    b = Alice::Concepts::IsVolatileVoid<decltype(Tester2)>;//false
    b = Alice::Concepts::IsVolatileVoid<decltype(Tester3)>;//true
    b = Alice::Concepts::IsVolatileVoid<decltype(Tester4)>;//true
}

void PureVoidTest()
{
    bool b = Alice::Concepts::IsPureVoid<decltype(Tester)>;//false
    b = Alice::Concepts::IsPureVoid<decltype(Tester2)>;//false
    b = Alice::Concepts::IsPureVoid<decltype(Tester3)>;//false
    b = Alice::Concepts::IsPureVoid<decltype(Tester4)>;//true
}