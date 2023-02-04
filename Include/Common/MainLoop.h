/**
 * Created by rayfalling on 2023-02-04.
 */

#pragma once

#ifndef PWOL_MAIN_LOOP_H
#define PWOL_MAIN_LOOP_H

#include <sys/types.h>
#include <sys/socket.h>

#include "ConfigParser/ConfigItem.h"

namespace PWol {
	// Main Loop and init static class
	class PWolMain
	{
	public:
		PWolMain() = default;

		// Init All config
		bool Init();

		// MainLoop
		void Loop();

	private:
		// Main Config With ConfigLoader
		Config::ConfigLoader Config;
	};
}

#endif //PWOL_MAIN_LOOP_H
