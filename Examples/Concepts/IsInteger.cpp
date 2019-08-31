#include <Concepts\IsInteger.hpp>

void IntegerTest()
{
    bool b = Alice::Concepts::IsInteger<bool>;//true
    b = Alice::Concepts::IsInteger<byte>;//true
    b = Alice::Concepts::IsInteger<s8>;//true
    b = Alice::Concepts::IsInteger<u8>;//true
    b = Alice::Concepts::IsInteger<s16>;//true
    b = Alice::Concepts::IsInteger<u16>;//true
    b = Alice::Concepts::IsInteger<s32>;//true
    b = Alice::Concepts::IsInteger<u32>;//true
    b = Alice::Concepts::IsInteger<s64>;//true
    b = Alice::Concepts::IsInteger<u64>;//true
    b = Alice::Concepts::IsInteger<f32>;//false
}