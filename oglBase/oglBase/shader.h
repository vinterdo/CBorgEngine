#pragma once
#include "asset.h"
#include "uniformValue.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string>

#include <GL/glew.h>
#include <glm.hpp>

class shader :
	public asset
{
public:
	shader(void);
	~shader(void);

	void start();
	void end();
	int getUniformId(std::string name);
	int getAttribId(std::string name);

	void setValue(std::string name, uniformValue* value)
	{
		value->passValue(name, programId);
	}

	virtual bool load(std::string path);
	static shader* loadNew(std::string path);

private:
	unsigned int programId;
};

