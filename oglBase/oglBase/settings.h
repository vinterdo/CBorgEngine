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
	std::string getAppName();

private:
	std::string appName;
	int resX;
	int resY;
	int fixedUpdatePS;
};

