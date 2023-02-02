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
			void LogDebug(std::string &message);

			void LogDebug(std::string &&message);

			void LogDebug(const std::string &message);

			/**
			 * Log default info
			 * */
			void LogInfo(std::string &message);

			void LogInfo(std::string &&message);

			void LogInfo(const std::string &message);

			/**
			 * Log warning info
			 * */
			void LogWarning(std::string &message);

			void LogWarning(std::string &&message);

			void LogWarning(const std::string &message);

			/**
			 * Log error info
			 * */
			void LogError(std::string &message);

			void LogError(std::string &&message);

			void LogError(const std::string &message);

			void SetLogLevel(LogLevel logLevel);

			/* Flush all */
			void FlushAll();
	};
}

#endif //PWOL_LOG_UTILS_H
