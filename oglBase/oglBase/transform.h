#pragma once
#include <glm.hpp>

class transform
{
public:
	transform(void);
	~transform(void);

	glm::vec3 getPos(void);
	void setPos(glm::vec3);
private:
	glm::vec3 position;
};

