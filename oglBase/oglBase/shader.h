#pragma once
#include "asset.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string>

#include <GL/glew.h>

enum uniformType
{
	intt,
	floatt,
	vector3t,
	mat4x4t
};

class shader :
	public asset
{
public:
	shader(void);
	~shader(void);

	void start();
	void end();

	template<class T>
	void setValue(std::string name, T value)
	{
		/*int location = glGetUniformLocation(programId, name.c_str());

		if(dynamic_cast<int>(value) != NULL)
		{
			glUniform1i(location, int(value)); 
		}
		else if(dynamic_cast<glm::vec3>(value) != NULL)
		{
			glUniform3fv(location, 1, &glm::vec3(value)[0]); 
		}*/
	}

	virtual bool load(std::string path);

private:
	unsigned int programId;
};

