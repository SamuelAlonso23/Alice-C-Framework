#include <Core\DefaultDelete.hpp>

void DefaultDeleteTest()
{
    f32* a = new f32(3.4f);
    Alice::DefaultDelete<f32> d;
    d(a);
}