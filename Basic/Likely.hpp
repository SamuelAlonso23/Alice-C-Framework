//Copyright Alice Framework, All Rights Reserved
#pragma once

#define AliceLikely(condition) __builtin_expect(static_cast<bool>(condition), 1)
#define AliceUnlikely(condition) __builtin_expect(static_cast<bool>(condition), 0)