#include <Concepts\RemoveVolatile.hpp>

//returns volatile bool
volatile bool NoRemovedVolatile()
{
    return volatile bool(true);
}

//returns bool
bool RemovedVolatile()
{
    return Alice::Concepts::RemoveVolatile<volatile bool>(true);
}