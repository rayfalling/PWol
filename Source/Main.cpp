/**
 * Created by root on 2023-02-02.
 */

#include <csignal>

#include "Common/MainLoop.h"
#include "Library/LogUtils.h"

int main()
{
	auto& logger = PWol::LogUtils::GetInstance();

	// Switch to daemon mode
#ifndef PWOL_DEBUG
	if (daemon(0, 0) == -1)
	{
		logger.LogError("PWol daemon start failed!");
		exit(-1);
	}
#endif


	PWol::PWolMain pWolMain;

	// Check program init success
	if (!pWolMain.Init())
	{
		logger.LogError("PWol daemon init failed!");
		exit(-1);
	}

	pWolMain.Loop();
	return 0;
}
