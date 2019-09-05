#include <System/CpuInfo.hpp>

void CpuInformation()
{
    Alice::System::GetCpuInfo();
    //Check cpu features after calling GetCpuInfo
    bool IsAdx = HasAdx();
    bool IsAvx512f = HasAvx512f();
}

bool HasAdx()
{
    return Alice::System::ISA::Adx;
}

bool HasAvx512f()
{
    return Alice::System::ISA::Avx512f;
}