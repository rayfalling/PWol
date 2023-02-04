/**
 * Created by rayfalling on 2023-02-04.
 */

#include "Common/MainLoop.h"

#include "Library/LogUtils.h"
#include "ConfigParser/ConfigItem.h"

bool PWol::PWolMain::Init()
{
	auto &logger = PWol::LogUtils::GetInstance();

#ifdef PWOL_DEBUG
	logger.SetLogLevel(PWol::LogLevel::Debug);
	logger.LogDebug("PWol LogLevel set to Debug!");
#endif
	logger.LogInfo("PWol Starting......");

	// Do load config
	logger.LogInfo("PWol loading config......");
	const auto configResult = Config.LoadPWolConfig();
	if (!configResult)
	{
		logger.LogError("PWol loading config failed, exiting");
		return false;
	}

	logger.LogInfo("PWol discovering pve config......");
	return true;
}

void PWol::PWolMain::Loop()
{
	// TODO loop
}
