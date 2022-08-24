#pragma once

#define WIN32_LEAN_AND_MEAN

#ifdef _DEBUG
#pragma comment(lib, "Debug\\ServerCore.lib")
#elif
#pragma commet(lib, "Release\\ServerCore.lib")
#endif // _DEBUG

#include "CorePch.h"