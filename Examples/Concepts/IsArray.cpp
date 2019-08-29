#include <Concepts\IsArray.hpp>

//returns false
bool NoArray()
{
    bool f = true;
    return Alice::Concepts::IsArray<decltype(f)>; 
}

//returns true
bool Array()
{
    bool f[1] = {true};
    return Alice::Concepts::IsArray<decltype(f)>;
}