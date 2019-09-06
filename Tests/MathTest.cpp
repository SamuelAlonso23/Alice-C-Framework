#include <Basic/Epsilon.hpp>
#include <Basic/Types.hpp>
#include <Math/Algebra/Ceil.hpp>
#include <Math/Algebra/Floor.hpp>
#include <Math/Algebra/Round.hpp>
#include <Math/Algebra/SquareRoot.hpp>
#include <Math/Arithmetic/AbsoluteValue.hpp>
#include <Math/Arithmetic/Maximum.hpp>
#include <Math/Arithmetic/Minimum.hpp>
#include <Tests/Test.hpp>

ALICE_TEST_CASE CeilTest()
{
    f32 outf(1.0);
    f64 outd(1.0);
    ALICE_TEST_ASSERT(Alice::Math::Algebra::Ceil<f32>(Epsilon32) == outf);
    ALICE_TEST_ASSERT(Alice::Math::Algebra::Ceil<f64>(Epsilon64) == outd);
}

ALICE_TEST_CASE FloorTest()
{
    f32 outf(0.0);
    f64 outd(0.0);
    ALICE_TEST_ASSERT(Alice::Math::Algebra::Floor<f32>(Epsilon32) == outf);
    ALICE_TEST_ASSERT(Alice::Math::Algebra::Floor<f64>(Epsilon64) == outd);
}

ALICE_TEST_CASE RoundTest()
{
    f32 inf(Epsilon32 + 0.5);
    f32 ind(Epsilon64 + 0.5);
    f32 outf(1.0);
    f64 outd(1.0);
    ALICE_TEST_ASSERT(Alice::Math::Algebra::Round<f32>(inf) == outf);
    ALICE_TEST_ASSERT(Alice::Math::Algebra::Round<f64>(ind) == outd);
}

// Please consider changing this to match the syntax of the other functions
ALICE_TEST_CASE SquareRootTest()
{
    f32 inf,outf;
    f64 ind,outd;
    // Test f32
    inf = 1.0;
    outf = 1.0;
    ALICE_TEST_ASSERT(Alice::Math::Algebra::SquareRoot(inf) == outf);
    inf = 16.0;
    outf = 4.0;
    ALICE_TEST_ASSERT(Alice::Math::Algebra::SquareRoot(inf) == outf);
    inf = 0.25;
    outf = 0.5;
    ALICE_TEST_ASSERT(Alice::Math::Algebra::SquareRoot(inf) == outf);
    // Test f64
    ind = 1.0;
    outd = 1.0;
    ALICE_TEST_ASSERT(Alice::Math::Algebra::SquareRoot(ind) == outd);
    ind = 16.0;
    outd = 4.0;
    ALICE_TEST_ASSERT(Alice::Math::Algebra::SquareRoot(ind) == outd);
    ind = 0.25;
    outd = 0.5;
    ALICE_TEST_ASSERT(Alice::Math::Algebra::SquareRoot(ind) == outd);
}

ALICE_TEST_CASE AbsoluteValueTest()
{
    f32 inf = Epsilon32 * -1.0;
    f64 ind = Epsilon64 * -1.0;
    ALICE_TEST_ASSERT(Alice::Math::Arithmetic::AbsoluteValue<f32>(inf) == Epsilon32);
    ALICE_TEST_ASSERT(Alice::Math::Arithmetic::AbsoluteValue<f64>(ind) == Epsilon64);
}

ALICE_TEST_CASE MaximumTest()
{
    ALICE_TEST_ASSERT(Alice::Math::Arithmetic::Maximum<f32>(Epsilon32, 0.0) == Epsilon32);
    ALICE_TEST_ASSERT(Alice::Math::Arithmetic::Maximum<f64>(Epsilon64, 0.0) == Epsilon64);
}

ALICE_TEST_CASE MinimumTest()
{
    ALICE_TEST_ASSERT(Alice::Math::Arithmetic::Minimum<f32>(Epsilon32, 0.0) == 0.0);
    ALICE_TEST_ASSERT(Alice::Math::Arithmetic::Minimum<f64>(Epsilon64, 0.0) == 0.0);
}

ALICE_UNIT_TEST
{
    CeilTest();
    FloorTest();
    RoundTest();
    SquareRootTest();
    AbsoluteValueTest();
    MaximumTest();
    MinimumTest();
}