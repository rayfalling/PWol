/**
 * Created by rayfalling on 2023-02-02.
 */

#include "ConfigParser/ConfigItem.h"

#include <fstream>
#include <filesystem>

#include "Library/Json.hpp"
#include "Library/LogUtils.h"

namespace PWol::Config {
	const std::string ConfigData::LXCConfigDir = "/lxc";
	const std::string ConfigData::QemuConfigDir = "/qemu-server";

	bool ConfigLoader::LoadPWolConfig()
	{
		const auto result = DiscoverPWolConfigFile();

		// Config file discover failed, skip
		if (!result)
		{
			return false;
		}

		return DoLoadPWolConfigFile();
	}

	bool ConfigLoader::LoadProxmoxVEConfig()
	{
		const auto result = DiscoverProxmoxVEConfig();
		// TODO Analyze next
		return false;
	}

	bool ConfigLoader::DiscoverPWolConfigFile()
	{
		bool hasValidConfigFile = false;

		// Do check all potential dir may exist config file
		for (const auto& potentialPath: potential_config_dir)
		{
			const auto configDirPath = std::filesystem::path(potentialPath);
			if (!std::filesystem::exists(configDirPath))
				continue;

			const auto fullFilePath = configDirPath / config_file;
			if (!std::filesystem::exists(fullFilePath))
				continue;

			// find config path and file, record it
			hasValidConfigFile = true;
			PwolConfigPath = fullFilePath;
			break;
		}

		return hasValidConfigFile;
	}

	bool ConfigLoader::DiscoverProxmoxVEConfig()
	{
		return false;
	}

	bool ConfigLoader::DoLoadPWolConfigFile()
	{
		using Json = nlohmann::json;

		Json json;
		const auto configFilePath = std::filesystem::absolute(std::filesystem::path(PwolConfigPath));

		// Try load json data
		try
		{
			std::ifstream configFile(configFilePath);
			json = Json::parse(configFile);
		}

#ifdef PWOL_DEBUG
		catch (Json::exception& exception)
		{
			auto& logger = PWol::LogUtils::GetInstance();
			logger.LogError(exception.what());
			return false;
		}
#else
		catch (Json::exception &)
		{
			return false;
		}
#endif

		Config.PVEConfigDir = json.value("/PVEPath"_json_pointer, Config.PVEConfigDir);
		return true;
	}
}
