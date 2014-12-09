#pragma once
#include "component.h"
#include <glm.hpp>
#include <vector>

// light types: spot, directional, point, area

class light :
	public component
{
public:
	light(glm::vec3 color, float power);
	~light(void);

	float getPower();
	glm::vec3 getColor();
	glm::vec3 getPos();

	void setPower(float);
	void setColor(glm::vec3);

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);

private:
	glm::vec3 color;
	float power;

	static std::vector<light*> lightList;
};

