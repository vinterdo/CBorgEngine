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

	void setValue(std::string name, uniformValue* value)
	{
		sh->setValue(name, value);
	}

	int getVertexModelspaceId();
	int getVertexUvId();
	int getNormalsId();
	shader* getShader();

private:
	shader* sh;
};

