//Copyright Alice Framework, All Rights Reserved
#include <Collections/Generic/List.hpp> // ListTest
#include <Tests/Test.hpp>

ALICE_TEST_CASE ListTest()
{
    Alice::Collections::Generic::List<int> list;
}

int main(const int argc, const char ** argv)
{
    ListTest();
    return 0;
}
