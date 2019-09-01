#include <Collections\Generic\List.hpp>
#include <iostream>

void ListTest()
{
    Alice::Collections::Generic::List<f32> vec(4);//reserve 4 f32 at initialization in the memory
    std::cout << std::boolalpha;
    std::cout << "List length is: " << vec.Length() << std::endl
    << "Is the list read only? " << vec.IsReadOnly() << std::endl;
    vec[0] = 9.8f;
    vec[1] = 4.3f;
    vec[2] = 0.1f;
    std::cout << "List capacity: " << vec.Capacity() << std::endl
    << "First element: " << vec[0] << std::endl << "Second element: " << vec[1] << std::endl
    << "Third element: " << vec[2] << std::endl << "Forth element: " << vec[3] << std::endl;
    vec.Resize(2);
    std::cout << "List capacity after resizing: " << vec.Capacity() << std::endl << "First element after resizing: " << vec[0] << std::endl << "Second element after resizing: " << vec[1] << std::endl;
}