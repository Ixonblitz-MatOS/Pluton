#pragma once
#include "plpch.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Core.h"
namespace Pluton {
	class PLUTON_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
//core log macros
#define PL_CORE_TRACE(...)      ::Pluton::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PL_CORE_WARN(...)       ::Pluton::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PL_CORE_INFO(...)       ::Pluton::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PL_CORE_ERROR(...)      ::Pluton::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PL_CORE_FATAL(...)      ::Pluton::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//client log macros
#define PL_CLIENT_TRACE(...)    ::Pluton::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PL_CLIENT_WARN(...)     ::Pluton::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PL_CLIENT_INFO(...)     ::Pluton::Log::GetClientLogger()->info(__VA_ARGS__)
#define PL_CLIENT_ERROR(...)    ::Pluton::Log::GetClientLogger()->error(__VA_ARGS__)
#define PL_CLIENT_FATAL(...)    ::Pluton::Log::GetClientLogger()->fatal(__VA_ARGS__)
