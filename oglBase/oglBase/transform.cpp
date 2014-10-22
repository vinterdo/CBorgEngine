#include "transform.h"


transform::transform(void)
{
}


transform::~transform(void)
{
}

glm::vec3 transform::getPos(void)
{
	return position;
}

void transform::setPos(glm::vec3 vec)
{
	position = vec;
}