#include <Basic\Types.hpp>
#include <Concepts\IsNullPtrType.hpp>

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
}

void ConstNullPtrTypeTest()
{
    bool b = Alice::Concepts::IsConstNullPtrType<decltype(Tester)>;//false
    b = Alice::Concepts::IsConstNullPtrType<decltype(Tester2)>;//true
    b = Alice::Concepts::IsConstNullPtrType<decltype(Tester3)>;//false
    b = Alice::Concepts::IsConstNullPtrType<decltype(Tester4)>;//true
}

void VolatileNullPtrTypeTest()
{
    bool b = Alice::Concepts::IsVolatileNullPtrType<decltype(Tester)>;//false
    b = Alice::Concepts::IsVolatileNullPtrType<decltype(Tester2)>;//false
    b = Alice::Concepts::IsVolatileNullPtrType<decltype(Tester3)>;//true
    b = Alice::Concepts::IsVolatileNullPtrType<decltype(Tester4)>;//true
}

void PureNullPtrTypeTest()
{
    bool b = Alice::Concepts::IsPureNullPtrType<decltype(Tester)>;//false
    b = Alice::Concepts::IsPureNullPtrType<decltype(Tester2)>;//false
    b = Alice::Concepts::IsPureNullPtrType<decltype(Tester3)>;//false
    b = Alice::Concepts::IsPureNullPtrType<decltype(Tester4)>;//true
}