//Copyright Alice Framework, All Rights Reserved
#include <Basic/Epsilon.hpp> // EpsilonTest
#include <Basic/ExceptionType.hpp> // Skipping for now
#include <Basic/Inline.hpp> // InlineTest
#include <Basic/Likely.hpp> // LikelyTest
#include <Basic/NoDefault.hpp> // Skipping for now
#include <Basic/Types.hpp> // TypesTest
#include <Tests/Test.hpp> // Skipping for now
#include <chrono>
#include <stdexcept>

// Test to make sure epsilon values are greater than 0.0
ALICE_TEST_CASE EpsilonTest()
{
    f32 zerof(0.0);
    f64 zerod(0.0);
    ALICE_TEST_ASSERT(Epsilon32 > zerof);
    ALICE_TEST_ASSERT(Epsilon64 > zerod);
}

class TestAdder
{
public:
    int Add(const int a, const int b)
    {
        return a + b;
    }
    
    AliceInline int InlineAdd(const int a, const int b)
    {
        return a + b;
    }
};

// Test to make sure inline functions provide performance boost
ALICE_TEST_CASE InlineTest()
{
    TestAdder Adder;
    auto Start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 1000; i++)
    {
        Adder.Add(i,i);
    }
    auto End = std::chrono::high_resolution_clock::now();
    auto Time = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    auto InlineStart = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 1000; i++)
    {
        Adder.InlineAdd(i,i);
    }
    auto InlineEnd = std::chrono::high_resolution_clock::now();
    auto InlineTime = std::chrono::duration_cast<std::chrono::nanoseconds>(InlineEnd - InlineStart);
    ALICE_TEST_ASSERT(Time > InlineTime);
}

// Make sure branch predictors work correctly
ALICE_TEST_CASE LikelyTest()
{
    bool b = true;
    bool likely(false);
    bool unlikely(true);
    if(AliceLikely(b))
    {
        likely = true;
    }
    if(AliceUnlikely(!b))
    {
        unlikely = false;
    }
    ALICE_TEST_ASSERT(likely && unlikely);
}

int main(const int argc, const char ** argv)
{
    EpsilonTest();
    InlineTest();
    LikelyTest();
    return 0;
}
