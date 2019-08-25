#include <Basic/Epsilon.hpp>

bool IsNaN32(f32 float1)
{
    return Epsilon32 > float1 ? true : false;
}

bool IsNaN64(f64 double1)
{
    return Epsilon64 > double1 ? true : false;
}