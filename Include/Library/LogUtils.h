/**
 * Created by root on 2023-02-02.
 */

#pragma once

#ifndef PWOL_LOG_UTILS_H
#define PWOL_LOG_UTILS_H

#include <spdlog/spdlog.h>

#include "Common/ISingletonObject.h"

namespace PWol {
	enum class LogLevel
	{
		Debug = 1,
		Info = 2,
		Warning = 3,
		Error = 4
	};

	class LogUtils final : public ISingletonObject<LogUtils>
	{
		friend class ISingletonObject<LogUtils>;

	protected:
		LogUtils();

		~LogUtils() noexcept override;

	public:
		LogUtils(const LogUtils &) = delete;

		LogUtils(const LogUtils &&) = delete;

		LogUtils &operator=(const LogUtils &) = delete;

		LogUtils &operator=(LogUtils &&) = delete;

	private:
		/* Core logger, static for over dll use */
		static std::shared_ptr<spdlog::logger> _logger;

		/* Shared sinks between different loggers */
		static std::vector<spdlog::sink_ptr> _sinks;

	public:
		/**
		 * Log debug info
		 * */
		[[maybe_unused]] void LogDebug(std::string &&message);

		[[maybe_unused]] void LogDebug(const std::string &message);

		/**
		 * Log default info
		 * */
		[[maybe_unused]] void LogInfo(std::string &&message);

		[[maybe_unused]] void LogInfo(const std::string &message);

		/**
		 * Log warning info
		 * */
		[[maybe_unused]] void LogWarning(std::string &&message);

		[[maybe_unused]] void LogWarning(const std::string &message);

		/**
		 * Log error info
		 * */
		[[maybe_unused]] void LogError(std::string &&message);

		[[maybe_unused]] void LogError(const std::string &message);

		/* Set all logger level */
		[[maybe_unused]] void SetLogLevel(LogLevel logLevel);

		/* Flush all */
		[[maybe_unused]] void FlushAll();
	};
}

#endif //PWOL_LOG_UTILS_H
