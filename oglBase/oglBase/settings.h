#pragma once
#include <string>

class settings
{
public:
	settings(void);
	~settings(void);

	int getResX();
	int getResY();
	int getFixedUpdatePS();
	bool getShowFPS();
	std::string getAppName();

	std::string appName;
	int resX;
	int resY;

private:
	int fixedUpdatePS;
	bool showFPS;
};

