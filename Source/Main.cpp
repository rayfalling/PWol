/**
 * Created by root on 2023-02-02.
 */

#include "Library/LogUtils.h"

int main() {
	auto &logger = PWol::LogUtils::GetInstance();

#ifdef PWOL_DEBUG
	logger.SetLogLevel(PWol::LogLevel::Debug);
	logger.LogDebug("PWol LogLeve set to Debug!");
#endif

	logger.LogInfo("PWol Starting......");

	return 0;
}
