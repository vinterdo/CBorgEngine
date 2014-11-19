#pragma once
#include "asset.h"
#include <gl\glew.h>
class material
{
public:
	material(void);
	~material(void);

	virtual bool load(std::string path);

	void begin();
	void end();

private:
	GLuint programID;
};

