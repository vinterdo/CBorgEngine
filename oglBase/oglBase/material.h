#pragma once
#include "asset.h"
#include "shader.h"
#include <gl\glew.h>
class material
{
public:
	material(void);
	~material(void);

	virtual bool load(std::string path);

	void begin();
	void end();

	void setShader(shader* _sh);
	template<class T>
	void setValue(std::string name, T value)
	{
		sh->setValue(name, value);
	}

private:
	shader* sh;
};

