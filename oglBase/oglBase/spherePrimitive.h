#pragma once
#include "component.h"
#include "mesh.h"
class spherePrimitive :
	public mesh
{
public:
	spherePrimitive(float radius, int rows, int columns);
	~spherePrimitive(void);

	virtual bool load(std::string path);

protected:

};

