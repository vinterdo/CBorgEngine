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

private:
	shader* sh;
};

