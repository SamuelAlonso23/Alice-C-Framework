#include <Core/Lazy.hpp>

class ReallyBigObject{};

void LazyTest()
{
    Alice::Lazy<ReallyBigObject> l;
    l = ReallyBigObject();
    const ReallyBigObject&& j = l.Object();
    l = j;
}