#include <Core\Exception.hpp>

void foo()
{
    bool SomethingHappens;
    if(SomethingHappens)
        Alice::Exception::Raise(Alice::ExceptionType::SomethingHappensException);
    foo2();
    foo3();
    foo4();
}

//returns true
bool foo2()
{
    return Alice::Exception::Check(Alice::ExceptionType::SomethingHappensException);
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