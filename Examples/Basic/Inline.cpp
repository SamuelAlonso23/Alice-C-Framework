#include <Basic/Inline.hpp>

//With constexpr
AliceInline constexpr void foo(){}

//With template
template<class Bar> AliceInline void foo2(){}

//Normal
AliceInline void foo3(){}