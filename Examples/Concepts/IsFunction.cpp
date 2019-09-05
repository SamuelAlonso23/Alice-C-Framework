#include <Concepts/IsFunction.hpp>

class Class
{
public:
    const void Tester() const{}

    volatile void Tester2(){}

    void Tester3() noexcept{}

    virtual void Tester4(){}

    void operator+(Class Other){}
};

float Tester5() noexcept
{
    return 9;
}

const void Tester6(){}

volatile void Tester7(){}

void operator*(Class a, Class b){}

void IsFunctionTest()
{
    Class a, c;
    bool b = Alice::Concepts::IsFunction<decltype(a.Tester)>;//false
    b = Alice::Concepts::IsFunction<decltype(a.Tester2)>;//false
    b = Alice::Concepts::IsFunction<decltype(a.Tester3)>;//false
    b = Alice::Concepts::IsFunction<decltype(a.Tester4)>;//false
    b = Alice::Concepts::IsFunction<decltype(Tester5)>;//true
    b = Alice::Concepts::IsFunction<decltype(Tester6)>;//true
    b = Alice::Concepts::IsFunction<decltype(Tester7)>;//true
    b = Alice::Concepts::IsFunction<decltype(a + c)>;//false
    b = Alice::Concepts::IsFunction<decltype(a * c)>;//false
}