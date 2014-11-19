#pragma once
#include <string>
class asset
{
public:
	asset(void);
	~asset(void);

	virtual bool load(std::string path) = 0;

};

