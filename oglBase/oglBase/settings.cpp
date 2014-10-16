#include "settings.h"


settings::settings(void)
{
	resX = 800;
	resY = 600;
	fixedUpdatePS = 60;
	appName = "New OGL app";
	showFPS = true;
}

settings::~settings(void)
{
}

//======================================

int settings::getResX()
{
	return resX;
}

int settings::getResY()
{
	return resY;
}

int settings::getFixedUpdatePS()
{
	return fixedUpdatePS;
}

std::string settings::getAppName()
{
	return appName;
}

bool settings::getShowFPS()
{
	return showFPS;
}