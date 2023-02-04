/**
 * Created by rayfalling on 2023-02-02.
 */

#pragma once

#ifndef PWOL_CONFIG_ITEM_H
#define PWOL_CONFIG_ITEM_H

#include <vector>
#include <string>

#include "Common/Macro.h"

namespace PWol::Config {
	// global pve config suffix
	const static std::string config_file = "pwol.conf";

	// global pve config suffix
	const static std::string pve_config_suffix = ".conf";

	// Path for PWol search config file
	const static std::vector<std::string> potential_config_dir = {
			"/etc/pwol/",
			"/usr/lib/pwol/etc/",
			"./config/"
	};

	struct [[maybe_unused]] ConfigData
	{
		// LXC virtualized container config dir
		const static std::string LXCConfigDir;

		// KVM virtualized machine config dir
		const static std::string QemuConfigDir;

		// Path to get pve config dir
		std::string PVEConfigDir = "/etc/pve";
	};

	class ConfigLoader
	{
	public:
		// constructor
		ConfigLoader() = default;

		// destructor
		~ConfigLoader() = default;

		// Do load config from disk
		bool LoadPWolConfig();

		// Do analyze ProxmoxVE config list
		bool LoadProxmoxVEConfig();

	protected:
		// Load config in file
		bool DoLoadPWolConfigFile();

		// Try to discover pwol config
		bool DiscoverPWolConfigFile();

		// Try to discover ProxmoxVE config
		bool DiscoverProxmoxVEConfig();

	private:
		// If PVE config is valid
		bool PVEConfigValid = false;
		// If PWol config is valid
		bool PWolConfigValid = false;

		// Discover config path
		UString PwolConfigPath;

		ConfigData Config;
	};
}

#endif //PWOL_CONFIG_ITEM_H
