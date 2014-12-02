#pragma once
#include "component.h"
#include <GL\glew.h>
#include <glm.hpp>

class simple2DCamMove :
	public component
{
public:
	simple2DCamMove(void);
	~simple2DCamMove(void);

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);

	float speed;
};

