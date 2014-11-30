#pragma once
#include "asset.h"
#include "uniformValue.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <map>

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
		if(values.find(name.c_str()) == values.end()) // if there is no key in map
		{
			values.insert(std::pair<std::string, uniformValue*>(name, value));
		}
		else
		{
			values[name] = value;
		}
		//value->passValue(name, programId);
	}

	virtual bool load(std::string path);
	static shader* loadNew(std::string path);

private:
	unsigned int programId;
	std::map<std::string, uniformValue*> values;
};

