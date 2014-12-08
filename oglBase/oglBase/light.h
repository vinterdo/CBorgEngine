#pragma once
#include "component.h"
#include <glm.hpp>
#include <vector>

// light types: spot, directional, point, area

class light :
	public component
{
public:
	light(void);
	~light(void);

private:
	glm::vec3 color;
	float power;

	std::vector<light*> lightList;
};

