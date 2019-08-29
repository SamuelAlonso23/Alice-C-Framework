#include <Concepts\RemoveConst.hpp>

//returns const bool
const bool NoRemovedConst()
{
    return const bool(true);
}

//returns bool
bool RemovedConst()
{
    return Alice::Concepts::RemoveConst<const bool>(true);
}