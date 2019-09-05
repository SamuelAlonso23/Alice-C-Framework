//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <System/CacheType.hpp>

namespace Alice
{
    namespace System
    {
        class CpuLevelCache
		{
		public:
			u8 CoresPerPackage;

			u16 ThreadsPerPackage;

			bool FullyAssociative = false;

			bool SelfInitializing = false;

			u8 CacheLevel;

			CacheType ct = CacheType::Null;

			u16 WaysOfAssociavity;

			u16 PhysicalLinePartitions;

			u16 SystemCoherencyLineSize;

			u32 Sets;

			bool ComplexIndexing = false;

			bool InclusiveOfLowerLevels = false;

			bool WriteBackInvalidate = false;
		};
    }
}