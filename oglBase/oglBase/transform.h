#pragma once
#include <glm.hpp>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>
#include <gtc/matrix_transform.hpp>

class transform
{
public:
	transform(void);
	~transform(void);

	glm::vec3 getPos(void);
	void setPos(glm::vec3 pos);

	glm::vec3 getScale(void);
	void setScale(glm::vec3 scale);

	glm::quat getRotation(void);
	void setRotation(glm::quat rot);

	glm::mat4 getModelMatrix(void);

private:
	glm::vec3 position;
	glm::vec3 scale;
	glm::quat rotation;
};

