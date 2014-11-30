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
#include <glm.hpp>

enum uniformEnum
{
	intt,
	floatt,
	vector3t,
	mat4x4t,
	unknown
};

template< class T >
struct uniformType
{
    static const uniformEnum value = uniformEnum::unknown;
};
template<>
struct uniformType< int* >
{
    static const uniformEnum value = uniformEnum::intt;
};
template<>
struct uniformType< float* >
{
    static const uniformEnum value = uniformEnum::floatt;
};
template<>
struct uniformType< glm::vec3* >
{
	static const uniformEnum value = uniformEnum::vector3t;
};
template<>
struct uniformType< glm::mat4* >
{
	static const uniformEnum value = uniformEnum::mat4x4t;
};

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

	template<class T>
	void setValue(std::string name, T value)
	{
		int location = glGetUniformLocation(programId, name.c_str());
		if(uniformType<T>::value == uniformEnum::intt)
		{
			glUniform1i(location, *(int*)(value));
		}
		else if(uniformType<T>::value == uniformEnum::floatt)
		{
			glUniform1f(location, *(float*)(value));
		}
		else if(uniformType<T>::value == uniformEnum::vector3t)
		{
			glUniform3fv(location,1, &(*(glm::vec3*)(value))[0]);
		}
		else if(uniformType<T>::value == uniformEnum::mat4x4t)
		{
			glUniformMatrix4fv(location, 1, GL_FALSE, &(*(glm::mat4*)(value))[0][0]);
		}
		else
		{
 			throw "typeNotAvalible";
		}
	}

	virtual bool load(std::string path);
	static shader* loadNew(std::string path);

private:
	unsigned int programId;
};

