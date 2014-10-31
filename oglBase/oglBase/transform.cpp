#include "transform.h"


transform::transform(void)
{
	position = glm::vec3(0, 0, 0);
	scale = glm::vec3(1,1,1);
	rotation = glm::quat(glm::vec3(0,0,0));
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

glm::vec3 transform::getScale(void)
{
	return scale;
}

void transform::setScale(glm::vec3 vec)
{
	scale = vec;
}

glm::quat transform::getRotation(void)
{
	return rotation;
}

void transform::setRotation(glm::quat quaternion)
{
	rotation = quaternion;
}

glm::mat4 transform::getModelMatrix(void)
{
	glm::mat4 mod = glm::translate(glm::mat4(1.0f), position);
	mod *= glm::toMat4(rotation);
	mod *= glm::scale(glm::mat4(1.0f), scale);

	return mod;
}