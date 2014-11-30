#pragma once

#include <string>
#include <GL/glew.h>
#include <glm.hpp>


class uniformValue
{
public:
	uniformValue(void);
	~uniformValue(void);

	virtual void passValue(std::string name, int programId) = 0;
};

class uniformMat4 : public uniformValue
{
public:
	uniformMat4(glm::mat4 mat)
	{
		value = mat;
	}

	glm::mat4 value;
	virtual void passValue(std::string name, int programId)
	{
		int location = glGetUniformLocation(programId, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
	}
};

class uniformVector3 : public uniformValue
{
public:
	uniformVector3(glm::vec3 vec)
	{
		value = vec;
	}

	glm::vec3 value;
	virtual void passValue(std::string name, int programId)
	{
		int location = glGetUniformLocation(programId, name.c_str());
		glUniform3fv(location, 1, &value[0]);
	}
};

class uniformInt : public uniformValue
{
public:
	uniformInt(int x)
	{
		value = x;
	}

	int value;
	virtual void passValue(std::string name, int programId)
	{
		int location = glGetUniformLocation(programId, name.c_str());
		glUniform1i(location, value);
	}
};

class uniformFloat : public uniformValue
{
public:
	uniformFloat(float x)
	{
		value = x;
	}

	float value;
	virtual void passValue(std::string name, int programId)
	{
		int location = glGetUniformLocation(programId, name.c_str());
		glUniform1f(location, value);
	}
};

