#include "pch.h"
#include "Log.h"

namespace Bflex
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	std::shared_ptr<spdlog::logger> Log::s_ServiceLogger;

	void Log::Init()
	{
		//spdlog::set_pattern("*** [%H:%M:%S %z] [thread %t] %v ***");

		s_CoreLogger = spdlog::stdout_color_mt("Core");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
		
		s_ServiceLogger = spdlog::stdout_color_mt("Service");
		s_ServiceLogger->set_level(spdlog::level::trace);
	}
}