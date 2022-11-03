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
#ifdef PL_ENABLE_ASSERTS
	#define PL_ASSER(x,...){if(!(x)){PL_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
	#define PL_CORE_ASSERT(x,...){if(!(x)){PL_CORE_ERROR("Assertion Failed: {0}",__va_args__;__debugbreak();)}}
#else
	#define PL_ASSERT(x,...)
	#define PL_CORE_ASSERT(x,...)
#endif
#define BIT(x) (1<<x)