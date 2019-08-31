#include <Basic\Types.hpp>
#include <Concepts\IsNullPtrType.hpp>

f32 Tester5;
const volatile NullPtrType Tester;
const NullPtrType Tester2;
volatile NullPtrType Tester3;
NullPtrType Tester4;

void NullPtrTypeTest()
{
    bool b = Alice::Concepts::IsNullPtrType<decltype(Tester)>;//true
    b = Alice::Concepts::IsNullPtrType<decltype(Tester2)>;//true
    b = Alice::Concepts::IsNullPtrType<decltype(Tester3)>;//true
    b = Alice::Concepts::IsNullPtrType<decltype(Tester4)>;//true
    b = Alice::Concepts::IsNullPtrType<decltype(Tester5)>;//false
}