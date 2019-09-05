#include <Concepts/IsLvalueReference.hpp>

void IsLvalueReferenceTest()
{
    bool bb = true;
    const bool& Var1 = bb;
    volatile bool& Var2 = bb;
    const volatile bool& Var3 = bb;
    bool& Var4 = bb;

    bool b = Alice::Concepts::IsLvalueReference<decltype(Var1)>;//true
    b = Alice::Concepts::IsLvalueReference<decltype(Var2)>;//true
    b = Alice::Concepts::IsLvalueReference<decltype(Var3)>;//true
    b = Alice::Concepts::IsLvalueReference<decltype(Var4)>;//true
    b = Alice::Concepts::IsLvalueReference<decltype(bb)>;//false
}