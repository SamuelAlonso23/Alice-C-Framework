//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <cpuid.h>
#include <System\CpuISA.hpp>
#include <Core\Exception.hpp>

namespace Alice
{
    namespace System
    {
        AliceInline void GetCpuInfo() noexcept
        {
            using namespace ISA;
            #if defined(AliceIos) || defined(AliceAndroid)
            Cpu = CpuType::Arm;
            
            #elif defined(AliceWindows) || defined(AliceLinux) || defined(AliceMac)
            u32 a, b, c, d;
            if(!__get_cpuid(0, &a, &b, &c, &d))
                Exception::Raise(ExceptionType::CpuIdNotSupported);
            else
            {
                if(b == 0x756e6547 && c == 0x6c65746e && d == 0x49656e69)
                    Cpu = CpuType::Intel;
                else
                    Cpu = CpuType::Amd;
            }
            if(!__get_cpuid(0x00000001, &a, &b, &c, &d))
                Exception::Raise(ExceptionType::CpuIdNotSupported);
            else
            {
                CacheLineFlushSize = (b << 16) >> 24;
                Hyperthreading = (d << 3) >> 31;
                if(Hyperthreading)
                    LogicalProcessorsPerEachPhysical = ((b << 8) >> 24);
                ProcessorId = b >> 24;
                FPU = (d << 31) >> 31;
                VirtualMode = (d << 30) >> 31;
                DebuggingExtensions = (d << 29) >> 31;
                PageSizeExtension = (d << 28) >> 31;
                TimeStampCounter = (d << 27) >> 31;
                ModelSpecificRegister = (d << 26) >> 31;
                PhysicalAddressExtension = (d << 25) >> 31;
                MachineCheckException = (d << 24) >> 31;
                Cmpxchg8 = (d << 23) >> 31;
                APIC = (d << 22) >> 31;
                Sysenterexit = (d << 20) >> 31;
                MemoryTypeRangeRegisters = (d << 19) >> 31;
                PageGlobal = (d << 18) >> 31;
                MachineCheckArchitecture = (d << 17) >> 31;
                ConditionalMove = (d << 16) >> 31;
                PageAttributeTable = (d << 15) >>31;
                PSE36 = (d << 14) >> 31;
                ProcessorSerialNumber = (d << 13) >> 31;
                Clflush = (d << 12) >> 31;
                DebugStore = (d << 10) >> 31;
                Acpi = (d << 9) >> 31;
                Mmx = (d << 8) >> 31;
                Fxsr = (d << 7) >> 31;
                Sse = (d << 6) >> 31;
                Sse2 = (d << 5) >> 31;
                SelfSnoopCache = (d << 4) >> 31;
                ThermalMonitor = (d << 2) >> 31;
                IA64 = (d << 1) >> 31;
                PendingBreak = d >> 31;
                Sse3 = (c << 31) >> 31;
                Pclmulqdq = (c << 30) >> 31;
                DebugStore64 = (c << 29) >> 31;
                MonitorMwait = (c << 28) >> 31;
                DebugStoreCpl = (c << 27) >> 31;
                VirtualMachineExtensions = (c << 26) >> 31;
                SaferModeExtensions = (c << 25) >> 31;
                SpeedStep = (c << 24) >> 31;
                ThermalMonitor2 = (c << 23) >> 31;
                Ssse3 = (c << 22) >> 31;
                L1ContextId = (c << 21) >> 31;
                SiliconDebugInterface = (c << 20) >> 31;
                Fma3 = (c << 19) >> 31;
                Cmpxchg16b = (c << 18) >> 31;
                Xtpr = (c << 17) >> 31;
                PerformanceAndDebugCapability = (c << 16) >> 31;
                ProcessContextIdentifiers = (c << 14) >> 31;
                DirectCacheAccess = (c << 13) >> 31;
                Sse41 = (c << 12) >> 31;
                Sse42 = (c << 11) >> 31;
                X2Apic = (c << 10) >> 31;
                Movbe = (c << 9) >> 31;
                Popcnt = (c << 8) >> 31;
                ApicTsc = (c << 7) >> 31;
                Aes = (c << 6) >> 31;
                Xsave = (c << 5) >> 31;
                Osxsave = (c << 4) >> 31;
                Avx = (c << 3) >> 31;
                F16c = (c << 2) >> 31;
                Rdrand = (c << 1) >> 31;
                Hypervisor = c >> 31;
            }
            c = 0;
            if(!__get_cpuid(0x00000004, &a, &b, &c, &d))
                Exception::Raise(ExceptionType::CpuIdNotSupported);
            else
            {
                CacheL1Data.CoresPerPackage = a >> 26;
                CacheL1Data.ThreadsPerPackage = (a << 6) >> 20;
                CacheL1Data.FullyAssociative = (a << 22) >> 31;
                CacheL1Data.SelfInitializing = (a << 23) >> 31;
                CacheL1Data.CacheLevel = (a << 24) >> 29;
                u8 cachetype = (a << 27) >> 27;
                if(cachetype == 1)
                    CacheL1Data.ct = CacheType::Data;
                else if(cachetype == 2)
                    CacheL1Data.ct = CacheType::Code;
                else if(cachetype == 3)
                    CacheL1Data.ct = CacheType::Unified;
                CacheL1Data.WaysOfAssociavity = b >> 22;
                CacheL1Data.PhysicalLinePartitions = (b << 10) >> 22;
                CacheL1Data.SystemCoherencyLineSize = (b << 20) >> 20;
                CacheL1Data.Sets = c;
                CacheL1Data.ComplexIndexing = (d << 29) >> 31;
                CacheL1Data.InclusiveOfLowerLevels = (d << 30) >> 31;
                CacheL1Data.WriteBackInvalidate = (d << 31) >> 31;
            }
            c = 1;
            if(!__get_cpuid(0x00000004, &a, &b, &c, &d))
                Exception::Raise(ExceptionType::CpuIdNotSupported);
            else
            {
                CacheL1Instruction.CoresPerPackage = a >> 26;
                CacheL1Instruction.ThreadsPerPackage = (a << 6) >> 20;
                CacheL1Instruction.FullyAssociative = (a << 22) >> 31;
                CacheL1Instruction.SelfInitializing = (a << 23) >> 31;
                CacheL1Instruction.CacheLevel = (a << 24) >> 29;
                u8 cachetype = (a << 27) >> 27;
                if(cachetype == 1)
                    CacheL1Instruction.ct = CacheType::Data;
                else if(cachetype == 2)
                    CacheL1Instruction.ct = CacheType::Code;
                else if(cachetype == 3)
                    CacheL1Instruction.ct = CacheType::Unified;
                CacheL1Instruction.WaysOfAssociavity = b >> 22;
                CacheL1Instruction.PhysicalLinePartitions = (b << 10) >> 22;
                CacheL1Instruction.SystemCoherencyLineSize = (b << 20) >> 20;
                CacheL1Instruction.Sets = c;
                CacheL1Instruction.ComplexIndexing = (d << 29) >> 31;
                CacheL1Instruction.InclusiveOfLowerLevels = (d << 30) >> 31;
                CacheL1Instruction.WriteBackInvalidate = (d << 31) >> 31;
            }
            c = 2;
            if(!__get_cpuid(0x00000004, &a, &b, &c, &d))
                Exception::Raise(ExceptionType::CpuIdNotSupported);
            else
            {
                CacheL2.CoresPerPackage = a >> 26;
                CacheL2.ThreadsPerPackage = (a << 6) >> 20;
                CacheL2.FullyAssociative = (a << 22) >> 31;
                CacheL2.SelfInitializing = (a << 23) >> 31;
                CacheL2.CacheLevel = (a << 24) >> 29;
                u8 cachetype = (a << 27) >> 27;
                if(cachetype == 1)
                    CacheL2.ct = CacheType::Data;
                else if(cachetype == 2)
                    CacheL2.ct = CacheType::Code;
                else if(cachetype == 3)
                    CacheL2.ct = CacheType::Unified;
                CacheL2.WaysOfAssociavity = b >> 22;
                CacheL2.PhysicalLinePartitions = (b << 10) >> 22;
                CacheL2.SystemCoherencyLineSize = (b << 20) >> 20;
                CacheL2.Sets = c;
                CacheL2.ComplexIndexing = (d << 29) >> 31;
                CacheL2.InclusiveOfLowerLevels = (d << 30) >> 31;
                CacheL2.WriteBackInvalidate = (d << 31) >> 31;
            }
            if(!__get_cpuid(0x00000005, &a, &b, &c, &d))
                Exception::Raise(ExceptionType::CpuIdNotSupported);
            else
            {
                SmallestMonitorLineSize = (a << 16) >> 16;
                LargestMonitorLineSize = (b << 16) >> 16;
                TreatInterruptsAsBreakEvents = (c << 30) >> 31;
            }
            if(!__get_cpuid(0x00000006, &a, &b, &c, &d))
                Exception::Raise(ExceptionType::CpuIdNotSupported);
            else
            {
                Hdc = (a << 18) >> 31;
                HwpPlr = (a << 20) >> 31;
                HwpEpp = (a << 21) >> 31;
                HwpAct = (a << 22) >> 31;
                HwpNot = (a << 23) >> 31;
                Hwp = (a << 24) >> 31;
                PackageThermalStatus = (a << 25) >> 31;
                ClockModulation = (a << 26) >> 31;
                ThermalStatusInterrupt = (a << 27) >> 31;
                AlwaysRunningAPIC = (a << 29) >> 31;
                DynamicAcceleration = (a << 30) >> 31;
                DigitalThermalSensor = (a << 31) >> 31;
                NumberOfDigitalThermalSensors = (b << 28) >> 28;
                EnergyPerformanceBIAS = (c << 28) >> 31;
                Acnt2 = (c << 30) >> 31;
                MaximumFrequencyClockCount = (c << 31) >> 31;
                ActualFrequencyClockCount = (c << 31) >> 31;
            }
            if(!__get_cpuid(0x00000007, &a, &b, &c, &d))
                Exception::Raise(ExceptionType::CpuIdNotSupported);
            else
            {
                AccessToBaseOfSegmentRegisters = (b << 31) >> 31;
                TscAdjust = (b << 30) >> 31;
                SoftwareGuard = (b << 29) >> 31;
                BitManipulation1 = (b << 28) >> 31;
                TransactionalSynchronizationHle = (b << 27) >> 31;
                Avx2 = (b << 26) >> 31;
                FPDataPointer = (b << 25) >> 31;
                SupervisorModeExecutionPrevention = (b << 24) >> 31;
                BitManipulation2 = (b << 23) >> 31;
                EnhancedMovsbStosb = (b << 22) >> 31;
                Invpcid = (b << 21) >> 31;
                TransactionalSynchronizationRtm = (b << 20) >> 31;
                PlatformQualityOfServiceMonitoring = (b << 19) >> 31;
                FpuSegmentRegistersAs0 = (b << 18) >> 31;
                MemoryProtection = (b << 17) >> 31;
                PlatformQualityOfServiceEnforcement = (b << 16) >> 31;
                Avx512f = (b << 15) >> 31;
                Avx512dq = (b << 14) >> 31;
                Rdseed = (b << 13) >> 31;
                Adx = (b << 12) >> 31;
                SupervisorModeAccessPrevention = (b << 11) >> 31;
                Avx512ifma = (b << 10) >> 31;
                Pcommit = (b << 9) >> 31;
                Clflushopt = (b << 8) >> 31;
                Clwb = (b << 7) >> 31;
                ProcessorTrace = (b << 6) >> 31;
                Avx512pf = (b << 5) >> 31;
                Avx512er = (b << 4) >> 31;
                Avx512cd = (b << 3) >> 31;
                Sha = (b << 2) >> 31;
                Avx512bw = (b << 1) >> 31;
                Avx512vl = b >> 31;
                Prefetchwt1 = (c << 31) >> 31;
                Avx512vbmi = (c << 30) >> 31;
                UserModeInstructionPrevention = (c << 29) >> 31;
                MemoryProtectionKeys = (c << 28) >> 31;
                OsMemoryProtectionKeys = (c << 27) >> 31;
                Avx512vbmi2 = (c << 25) >> 31;
                Cet = (c << 24) >> 31;
                Gfni = (c << 23) >> 31;
                Vaes = (c << 22) >> 31;
                Vpclmulqdq = (c << 21) >> 31;
                Avx512vnni = (c << 20) >> 31;
                Avx512bitalg = (c << 19) >> 31;
                TotalMemoryEncryption = (c << 18) >> 31;
                Avx512vpopcntdq = (c << 17) >> 31;
                Va57 = (c << 15) >> 31;
                Mawau = (c << 14) >> 31;
                ReadProcessorId = (c << 9) >> 31;
                SgxLaunchConfiguration = (c << 1) >> 31;
                Avx5124vnniw = (d << 29) >> 31;
                Avx5124fmaps = (d << 28) >> 31;
                PlatformConfiguration = (d << 13) >> 31;
                SpeculationControl = (d << 5) >> 31;
                SingleThreadIndirectBranchPredictor = (d << 4) >> 31;
                IA32ArchCapabilities = (d << 2) >> 31;
                SpeculativeStoreBypassDisable = d >> 31;
            }
            if(!__get_cpuid(0x0000009, &a, &b, &c, &d))
                Exception::Raise(ExceptionType::CpuIdNotSupported);
            else
                DirectCacheAccessParameters = a;
            if(!__get_cpuid(0x00000015, &a, &b, &c, &d))
                Exception::Raise(ExceptionType::CpuIdNotSupported);
            else
                CoreCrystalClockFrequency = c;
            if(!__get_cpuid(0x80000001, &a, &b, &c, &d))
                Exception::Raise(ExceptionType::CpuIdNotSupported);
            else
            {
                MultiprocessorCapable = (d << 12) >> 31;
                NoExecute = (d << 11) >> 31;
                ExtendedMmx = (d << 9) >> 31;
                GibibytePages = (d << 5) >> 31;
                Rdtscp = (d << 4) >> 31;
                LongMode = (d << 2) >> 31;
                _3dnow = d >> 31;
                Extended3dnow = (d << 1) >> 31;
                LahfSahfInLongMode = (c << 31) >> 31;
                HyperthreadingNotValid = (c << 30) >> 31;
                SecureVirtualMachine = (c << 29) >> 31;
                ExtendedApic = (c << 28) >> 31;
                Cr8In32Bits = (c << 27) >> 31;
                AdvancedBitManipulation = (c << 26) >> 31;
                Sse4a = (c << 25) >> 31;
                MisalignedSseMode = (c << 24) >> 31;
                Prefetch3dnow = (c << 23) >> 31;
                OsVisibleWorkaround = (c << 22) >> 31;
                InstructionBasedSampling = (c << 21) >> 31;
                Xop = (c << 20) >> 31;
                SkinitStgi = (c << 19) >> 31;
                WatchdogTimer = (c << 18) >> 31;
                LightweightProfiling = (c << 16) >> 31;
                Fma4 = (c << 15) >> 31;
                TranslationCache = (c << 14) >> 31;
                NodeIdMsr = (c << 12) >> 31;
                TrailingBitManipulations = (c << 10) >> 31;
                Topology = (c << 9) >> 31;
                CorePerformanceCounter = (c << 8) >> 31;
                NbPerformanceCounter = (c << 7) >> 31;
                DataBreakpoint = (c << 5) >> 31;
                PerformanceTsc = (c << 4) >> 31;
                L2iPerformanceCounter = (c << 3) >> 31;
                MonitorxMwaitx = c >> 31;
                #endif
            }
        }
    }
}