#pragma once
#include "component.h"
#include <glm.hpp>
class orbitCamera :
	public component
{
public:
	orbitCamera(glm::vec3 _center, float _radius);
	~orbitCamera(void);

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);

	float rotateSpeed;
	float zoomSpeed;

protected:
	glm::vec3 center;
	float radius;
	float rotX;
	float rotY;
};

