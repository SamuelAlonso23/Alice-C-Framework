//Copyright Alice Framework, All Rights Reserved
#include <Concepts/AddConst.hpp>
#include <Concepts/AddConstVolatile.hpp>
#include <Concepts/AddLvalueReference.hpp>
#include <Concepts/AddPointer.hpp>
#include <Concepts/AddRvalueReference.hpp>
#include <Concepts/AddVolatile.hpp>
#include <Concepts/Conditional.hpp>
#include <Concepts/DeclaredValue.hpp>
#include <Concepts/EnableIf.hpp>
#include <Concepts/IsArray.hpp>
#include <Concepts/IsArray.hpp>
#include <Concepts/IsClass.hpp>
#include <Concepts/IsConst.hpp>
#include <Concepts/IsConvertible.hpp>
#include <Concepts/IsEnum.hpp>
#include <Concepts/IsFloatingPoint.hpp>
//#include <Concepts/IsFunction.hpp> There is an issue with this class
#include <Concepts/IsInteger.hpp>
#include <Concepts/IsLvalueReference.hpp>
#include <Concepts/IsNullPtrType.hpp>
#include <Concepts/IsPointer.hpp>
#include <Concepts/IsRvalueReference.hpp>
#include <Concepts/IsSame.hpp>
#include <Concepts/IsUnion.hpp>
#include <Concepts/IsVoid.hpp>
#include <Concepts/IsVolatile.hpp>
#include <Concepts/RemoveConst.hpp>
#include <Concepts/RemoveReferences.hpp>
#include <Concepts/RemoveVolatile.hpp>
#include <Tests/Test.hpp>

ALICE_TEST_CASE AddConstTest()
{
    
}

ALICE_TEST_CASE AddConstVolatileTest()
{

}

ALICE_TEST_CASE AddLvalueReferenceTest()
{

}



int main(const int argc, const char ** argv)
{
    AddConstTest();
    AddConstVolatileTest();
    AddLvalueReferenceTest();
    return 0;
}