#pragma once
#include "asset.h"
class tex2d :
	public asset
{
public:
	tex2d(void);
	~tex2d(void);

	virtual bool load(std::string path);
	int getId();

private:
	int texId;
};

