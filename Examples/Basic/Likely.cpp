#include <Basic/Likely.hpp>

void LikelyTest()
{
    bool b = true;
    if(AliceLikely(b))
    {
        //branch predictor will be omitted and the CPU will execute this code directly
    }
}

void UnlikelyTest()
{
    bool b = true;
    if(AliceUnlikely(!b))
    {
        //branch predictor will be omitted and the CPU will execute this code directly
    }
}