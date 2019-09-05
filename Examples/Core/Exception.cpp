#include <Core/Exception.hpp>

void foo()
{
    bool SomethingHappens;
    if(SomethingHappens)
        Alice::Exception::Raise(ExceptionType::OperationWithoutSuccess);
    foo2();
    foo3();
    foo4();
}

//returns true
bool foo2()
{
    return Alice::Exception::Check(ExceptionType::OperationWithoutSuccess);
}

//returns true
bool foo3()
{
    return Alice::Exception::CheckAndReset(Alice::ExceptionType::SomethingHappensException);
}

//returns false, because CheckAndReset of foo3 set the Exception variable to None, so it is not SomethingHappensException anymore
bool foo4()
{
    return Alice::Exception::Check(Alice::ExceptionType::SomethingHappensException);
}