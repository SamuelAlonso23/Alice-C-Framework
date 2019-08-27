#include <Core\Array.hpp>

void ArrayCreation()
{
    //Compile error because 309.9 default type isn't s16
    Alice::Array<s16, 3> arr = {309.9, 10, 1};
    //Fine
    Alice::Array<s16, 3> arr2 = {208, 0, 1};
    //Fine
    Alice::Array<s16, 3> arr3 = {20};
    //Fine, but it will ignore the elements that exceed the size of the array
    Alice::Array<s16, 3> arr4 = {9, 8, 7, 5, 3};
    //Fine
    Alice::Array<s16, 3> arr5;
}

void ReadOnly()
{
    Alice::Array<s16, 3> arr2 = {208, 0, 1};
    bool RO = arr2.IsReadOnly();
    //RO is false
    arr2.AsReadOnly();
    RO = arr2.IsReadOnly();
    //RO is true
}

//returns 3, the number of elements at the array
u64 ArraySize()
{
    Alice::Array<s16, 3> arr2 = {208, 0, 1};
    return arr2.Size();
}

//returns 6, the number of elements * the size of the type(s16 at this case) in bytes(2 at this case)
u64 ArrayLength()
{
    Alice::Array<s16, 3> arr2 = {208, 0, 1};
    return arr2.Length;
}

//returns 208
s16 GetArrayElement()
{
    Alice::Array<s16, 3> arr2 = {208, 0, 1};
    return arr2[0];
}

void SetArrayElement()
{
    Alice::Array<s16, 3> arr2 = {208, 0, 1};
    //Now index 0 of arr2 instead of being 208, is 20
    arr2[0] = 20;
}

void CopyArray()
{
    Alice::Array<s16, 3> arr2 = {208, 0, 1};
    Alice::Array<s16, 1> arr = {1};
    //arr[0] is 1
    arr2.Copy(arr);
    //Now after the Copy, arr[0] is 208
}

//returns 0, because the index of 208 at arr2 is 0
u64 BinarySearch()
{
    Alice::Array<s16, 3> arr2 = {208, 0, 1};
    return arr2.BinarySearch(208);
}

//returns true, because arr2 contains an element with value 208
bool Exists()
{
    Alice::Array<s16, 3> arr2 = {208, 0, 1};
    return arr2.Exists(208);
}

void FullClear()
{
    Alice::Array<s16, 3> arr2 = {208, 0, 1};
    arr2.Clear();
    //all elements of arr2 are set to the default constructor, at this case 0
}

void PartialClear()
{
    Alice::Array<s16, 3> arr2 = {208, 0, 1};
    arr2.Clear(1, 1);
    //the elements of arr2 from index 1, to index 1, are set to the default constructor, at this case 0
}