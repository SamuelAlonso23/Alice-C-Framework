#include <Concepts\IsRvalueReference.hpp>

void IsRvalueReferenceTest()
{
    const bool&& Var1 = true;
    volatile bool&& Var2 = true;
    const volatile bool&& Var3 = true;
    bool&& Var4 = true;
    bool Var5 = true;

    bool b = Alice::Concepts::IsRvalueReference<decltype(Var1)>;//true
    b = Alice::Concepts::IsRvalueReference<decltype(Var2)>;//true
    b = Alice::Concepts::IsRvalueReference<decltype(Var3)>;//true
    b = Alice::Concepts::IsRvalueReference<decltype(Var4)>;//true
    b = Alice::Concepts::IsRvalueReference<decltype(Var5)>;//false
}