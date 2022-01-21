#pragma once
#include "pch.h"

namespace Bflex
{
	class CORE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetServiceLogger() { return s_ServiceLogger; }

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_ServiceLogger;

	};
}

// Core log macros
#define FX_CORE_ERROR(...)    ::Bflex::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FX_CORE_INFO(...)     ::Bflex::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FX_CORE_WARN(...)     ::Bflex::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FX_CORE_ERROR(...)    ::Bflex::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FX_CORE_CRITICAL(...) ::Bflex::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Service log macros
#define FX_SERVICE_ERROR(...)    ::Bflex::Log::GetServiceLogger()->trace(__VA_ARGS__)
#define FX_SERVICE_INFO(...)     ::Bflex::Log::GetServiceLogger()->info(__VA_ARGS__)
#define FX_SERVICE_WARN(...)     ::Bflex::Log::GetServiceLogger()->warn(__VA_ARGS__)
#define FX_SERVICE_ERROR(...)    ::Bflex::Log::GetServiceLogger()->error(__VA_ARGS__)
#define FX_SERVICE_CRITICAL(...) ::Bflex::Log::GetServiceLogger()->critical(__VA_ARGS__)

// Client log macros
#define FX_TRACE(...)         ::Bflex::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FX_INFO(...)          ::Bflex::Log::GetClientLogger()->info(__VA_ARGS__)
#define FX_WARN(...)          ::Bflex::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FX_ERROR(...)         ::Bflex::Log::GetClientLogger()->error(__VA_ARGS__)
#define FX_CRITICAL(...)      ::Bflex::Log::GetClientLogger()->critical(__VA_ARGS__)