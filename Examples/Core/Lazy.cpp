#include <Core\Lazy.hpp>

class ReallyBigObject{};

void LazyTest()
{
    Alice::Lazy<ReallyBigObject> l;
    l = ReallyBigObject();
    ReallyBigObject j = l.Object();
}