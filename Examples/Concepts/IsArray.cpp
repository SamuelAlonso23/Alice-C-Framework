#include <Concepts/IsArray.hpp>

//returns false
bool NoArray()
{
    bool f = true;
    return Alice::Concepts::IsArray<decltype(f)>; 
}

//returns true
bool Array()
{
    bool f[1];
    return Alice::Concepts::IsArray<decltype(f)>;
}

void IsArrayTest()
{
    bool bb = false;
    const bool arr[1] = {true};
    volatile bool arr2[1] = {true};
    const volatile bool arr3[1] = {true};
    bool arr4[1] = {true};

    bool b = Alice::Concepts::IsArray<decltype(arr)>;//true
    b = Alice::Concepts::IsArray<decltype(arr2)>;//true
    b = Alice::Concepts::IsArray<decltype(arr3)>;//true
    b = Alice::Concepts::IsArray<decltype(arr4)>;//true
    b = Alice::Concepts::IsArray<decltype(bb)>;//false
}