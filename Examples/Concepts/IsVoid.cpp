#include <Concepts/IsVoid.hpp>

volatile const void Tester;
const void Tester2;
volatile void Tester3;
void Tester4;
void Tester5();
float Tester6 = 9.9f;

void VoidTest()
{
    bool b = Alice::Concepts::IsVoid<decltype(Tester)>;//true
    b = Alice::Concepts::IsVoid<decltype(Tester2)>;//true
    b = Alice::Concepts::IsVoid<decltype(Tester3)>;//true
    b = Alice::Concepts::IsVoid<decltype(Tester4)>;//true
    b = Alice::Concepts::IsVoid<decltype(Tester5)>;//false
    b = Alice::Concepts::IsVoid<decltype(Tester6)>;//false
}