/**
 * Created by root on 2023-02-02.
 */

#pragma warning(disable:4068)
#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#pragma clang diagnostic push
#pragma ide diagnostic ignored "exit-time-destructors"

#include "Library/LogUtils.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

/* static shared_ptr to share logger in different library */
std::shared_ptr<spdlog::logger> PWol::LogUtils::_logger = std::shared_ptr<spdlog::logger>();
std::vector<spdlog::sink_ptr> PWol::LogUtils::_sinks = std::vector<spdlog::sink_ptr>();

const static std::string log_name = "PWol";

PWol::LogUtils::LogUtils()
{
	if (_logger != nullptr)return;
	/* Create sinks for logger */
	auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	consoleSink->set_level(spdlog::level::info);

#ifdef PWOL_DEBUG
	const std::string outFilePath = "/var/log/pwol.log";
#else
	const std::string outFilePath = "./log/pwol.log";
#endif
	auto fileSink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
			outFilePath, 8 * 1024 * 1024, 3, true
	);
	fileSink->set_level(spdlog::level::info);

	_sinks.emplace_back(consoleSink);
	_sinks.emplace_back(fileSink);

	/* register core logger */
	_logger = std::make_shared<spdlog::logger>(log_name, begin(_sinks), end(_sinks));
	_logger->set_level(spdlog::level::info);
	spdlog::flush_every(std::chrono::seconds(3));
	_logger->enable_backtrace(1024);
}

void PWol::LogUtils::LogInfo(std::string &message)
{
	_logger->info(message);
	_logger->flush();
}

void PWol::LogUtils::LogInfo(std::string &&message)
{
	_logger->info(message);
	_logger->flush();
}

void PWol::LogUtils::LogInfo(const std::string &message)
{
	_logger->info(message);
	_logger->flush();
}

void PWol::LogUtils::LogWarning(std::string &message)
{
	_logger->warn(message);
	_logger->flush();
}

void PWol::LogUtils::LogWarning(std::string &&message)
{
	_logger->warn(message);
	_logger->flush();
}

void PWol::LogUtils::LogWarning(const std::string &message)
{
	_logger->warn(message);
	_logger->flush();
}

void PWol::LogUtils::LogError(std::string &message)
{
	_logger->error(message);
	_logger->flush();
}

void PWol::LogUtils::LogError(std::string &&message)
{
	_logger->error(message);
	_logger->flush();
}

void PWol::LogUtils::LogError(const std::string &message)
{
	_logger->error(message);
	_logger->flush();
}

void PWol::LogUtils::LogDebug(std::string &message)
{
	_logger->debug(message);
	_logger->flush();
}

void PWol::LogUtils::LogDebug(std::string &&message)
{
	_logger->debug(message);
	_logger->flush();
}

void PWol::LogUtils::LogDebug(const std::string &message)
{
	_logger->debug(message);
	_logger->flush();
}

void PWol::LogUtils::SetLogLevel(const LogLevel logLevel)
{
	switch (logLevel)
	{
		case LogLevel::Debug:
			_logger->set_level(spdlog::level::debug);
			break;
		case LogLevel::Info:
			_logger->set_level(spdlog::level::info);
			break;
		case LogLevel::Warning:
			_logger->set_level(spdlog::level::warn);
			break;
		case LogLevel::Error:
			_logger->set_level(spdlog::level::err);
			break;
	}
}

void PWol::LogUtils::FlushAll()
{
	_logger->flush();
}

PWol::LogUtils::~LogUtils() noexcept = default;

#pragma clang diagnostic pop
#pragma clang diagnostic pop
