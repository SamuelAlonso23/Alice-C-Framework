#include <Concepts/IsPointer.hpp>

void IsPointerTest()
{
    const bool* Ptr;
    volatile bool* Ptr2;
    const volatile bool* Ptr3;
    bool* Ptr4;
    float Var1;
    
    bool b = Alice::Concepts::IsPointer<decltype(Ptr)>;//true
    b = Alice::Concepts::IsPointer<decltype(Ptr2)>;//true
    b = Alice::Concepts::IsPointer<decltype(Ptr3)>;//true
    b = Alice::Concepts::IsPointer<decltype(Ptr4)>;//true
    b = Alice::Concepts::IsPointer<decltype(Var1)>;//false
}