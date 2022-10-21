#pragma once
#ifdef PL_PLATFORM_WINDOWS
	#ifdef PL_BUILD_DLL
		#define PLUTON_API __declspec(dllexport)
	#else
		#define PLUTON_API __declspec(dllimport)
	#endif
#else
	#error Pluton only supports Windows!
#endif

#define BIT(x) (1<<x)