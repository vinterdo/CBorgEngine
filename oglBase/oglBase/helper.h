#pragma once
#include <string>

class helper
{
public:
	helper(void);
	~helper(void);

	static std::string getExtension(std::string path)
	{
		return path.substr(path.find_last_of(".") + 1);
	}

	static std::string getFullFileName(std::string path)
	{
		return path.substr(path.find_last_of("/\\") + 1);
	}

	static std::string getPath(std::string path)
	{
		return path.substr(0, path.find_last_of("/\\"));
	}

	static std::string getFileName(std::string path)
	{
		std::string ffn = getFullFileName(path);
		return ffn.substr(0, ffn.find_last_of("."));
	}

	static float clamp(float x, float a, float b)
	{
		return x < a ? a : (x > b ? b : x);
	}
};

