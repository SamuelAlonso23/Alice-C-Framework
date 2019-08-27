//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <System\CpuType.hpp>
#include <System\CpuCacheLevel.hpp>

namespace Alice
{
    namespace System
    {
        namespace ISA
        {
            CpuType Cpu = CpuType::Unknown;

            u8 CacheLineFlushSize;

		    u8 LogicalProcessorsPerEachPhysical;

		    bool Hyperthreading = false;

		    u8 ProcessorId;

		    bool FPU = false;

		    bool VirtualMode = false;

		    bool DebuggingExtensions = false;

		    bool PageSizeExtension = false;

		    bool TimeStampCounter = false;

		    bool ModelSpecificRegister = false;

		    bool PhysicalAddressExtension = false;

		    bool MachineCheckException = false;

		    bool Cmpxchg8 = false;

		    bool APIC = false;

		    bool Sysenterexit = false;

		    bool MemoryTypeRangeRegisters = false;

		    bool PageGlobal = false;

		    bool MachineCheckArchitecture = false;

		    bool ConditionalMove = false;

		    bool PageAttributeTable = false;

		    bool PSE36 = false;

	    	bool ProcessorSerialNumber = false;

		    bool Clflush = false;

		    bool DebugStore = false;

    		bool Acpi = false;

    		bool Mmx = false;

    		bool Fxsr = false;

	    	bool Sse = false;

		    bool Sse2 = false;

		    bool SelfSnoopCache = false;

    		bool ThermalMonitor = false;

	    	bool IA64 = false;

		    bool PendingBreak = false;

    		bool Sse3 = false;

	    	bool Pclmulqdq = false;

		    bool DebugStore64 = false;

        	bool MonitorMwait = false;

		    bool DebugStoreCpl = false;

		    bool VirtualMachineExtensions = false;

    		bool SaferModeExtensions = false;

	    	bool SpeedStep = false;

		    bool ThermalMonitor2 = false;

    		bool Ssse3 = false;

	    	bool L1ContextId = false;

		    bool SiliconDebugInterface = false;

		    bool Fma3 = false;

    		bool Cmpxchg16b = false;

    		bool Xtpr = false;

    		bool PerformanceAndDebugCapability = false;

	    	bool ProcessContextIdentifiers = false;

	    	bool DirectCacheAccess = false;

    		bool Sse41 = false;

	    	bool Sse42 = false;

		    bool X2Apic = false;

    		bool Movbe = false;

	    	bool Popcnt = false;

		    bool ApicTsc = false;

		    bool Aes = false;

    		bool Xsave = false;

	    	bool Osxsave = false;

		    bool Avx = false;

    		bool F16c = false;

	    	bool Rdrand = false;

		    bool Hypervisor = false;

            CpuLevelCache CacheL1Data;

		CpuLevelCache CacheL1Instruction;

		CpuLevelCache CacheL2;

		u16 SmallestMonitorLineSize;

		u16 LargestMonitorLineSize;

		bool TreatInterruptsAsBreakEvents = false;

		bool Hdc = false;

		bool HwpPlr = false;

		bool HwpEpp = false;

		bool HwpAct = false;

		bool HwpNot = false;

		bool Hwp = false;

		bool PackageThermalStatus = false;

		bool ClockModulation = false;

		bool ThermalStatusInterrupt = false;

		bool AlwaysRunningAPIC = false;

		bool DynamicAcceleration = false;

		bool DigitalThermalSensor = false;

		u8 NumberOfDigitalThermalSensors;

		bool EnergyPerformanceBIAS = false;

		bool Acnt2 = false;

		bool MaximumFrequencyClockCount = false;

		bool ActualFrequencyClockCount = false;

		bool AccessToBaseOfSegmentRegisters = false;

		bool TscAdjust = false;

		bool SoftwareGuard = false;

		bool BitManipulation1 = false;

		bool TransactionalSynchronizationHle = false;

		bool Avx2 = false;

		bool FPDataPointer = false;

		bool SupervisorModeExecutionPrevention = false;

		bool BitManipulation2 = false;

		bool EnhancedMovsbStosb = false;

		bool Invpcid = false;

		bool TransactionalSynchronizationRtm = false;

		bool PlatformQualityOfServiceMonitoring = false;

		bool FpuSegmentRegistersAs0 = false;

		bool MemoryProtection = false;

		bool PlatformQualityOfServiceEnforcement = false;

		bool Avx512f = false;

		bool Avx512dq = false;

		bool Rdseed = false;

		bool Adx = false;

		bool SupervisorModeAccessPrevention = false;

		bool Avx512ifma = false;

		bool Pcommit = false;

		bool Clflushopt = false;

		bool Clwb = false;

		bool ProcessorTrace = false;

		bool Avx512pf = false;

		bool Avx512er = false;

		bool Avx512cd = false;

		bool Sha = false;

		bool Avx512bw = false;

		bool Avx512vl = false;

		bool Prefetchwt1 = false;

		bool Avx512vbmi = false;

		bool UserModeInstructionPrevention = false;

		bool MemoryProtectionKeys = false;

		bool OsMemoryProtectionKeys = false;

		bool Avx512vbmi2 = false;

		bool Cet = false;

		bool Gfni = false;

		bool Vaes = false;

		bool Vpclmulqdq = false;

		bool Avx512vnni = false;

		bool Avx512bitalg = false;

		bool TotalMemoryEncryption = false;

		bool Avx512vpopcntdq = false;

		bool Va57 = false;

		bool Mawau = false;

		bool ReadProcessorId = false;

		bool SgxLaunchConfiguration = false;

		bool Avx5124vnniw = false;

		bool Avx5124fmaps = false;

		bool PlatformConfiguration = false;

		bool SpeculationControl = false;

		bool SingleThreadIndirectBranchPredictor = false;

		bool IA32ArchCapabilities = false;

		bool SpeculativeStoreBypassDisable = false;

		u32 DirectCacheAccessParameters;

		u32 CoreCrystalClockFrequency;

		u32 CoreBaseFrequency;

		u32 CoreMaximumFrequency;

		u32 BusFrequency;

		bool MultiprocessorCapable = false;

		bool NoExecute = false;

		bool ExtendedMmx = false;

		bool GibibytePages = false;

		bool Rdtscp = false;

		bool LongMode = false;

		bool _3dnow = false;

		bool Extended3dnow = false;

		bool LahfSahfInLongMode = false;

		bool HyperthreadingNotValid = false;

		bool SecureVirtualMachine = false;

		bool ExtendedApic = false;

		bool Cr8In32Bits = false;

		bool AdvancedBitManipulation = false;

		bool Sse4a = false;

		bool MisalignedSseMode = false;

		bool Prefetch3dnow = false;

		bool OsVisibleWorkaround = false;

		bool InstructionBasedSampling = false;

		bool Xop = false;

		bool SkinitStgi = false;

		bool WatchdogTimer = false;

		bool LightweightProfiling = false;

		bool Fma4 = false;

		bool TranslationCache = false;

		bool NodeIdMsr = false;

		bool TrailingBitManipulations = false;

		bool Topology = false;

		bool CorePerformanceCounter = false;

		bool NbPerformanceCounter = false;

		bool DataBreakpoint = false;

		bool PerformanceTsc = false;

		bool L2iPerformanceCounter = false;

		bool MonitorxMwaitx = false;
        }
    }
}