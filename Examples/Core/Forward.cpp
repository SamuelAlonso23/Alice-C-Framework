#include <Basic/Types.hpp>
#include <Core/Forward.hpp>

void foo()
{
    f32&& va = Alice::Forward<f32>(32.2f);
}