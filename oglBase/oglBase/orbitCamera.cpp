#include "orbitCamera.h"
#include "camera.h"
#include "input.h"
#include "helper.h"
orbitCamera::orbitCamera(glm::vec3 _center, float _radius)
{
	center = _center;
	radius = _radius;
	rotY = 0;
	rotX = 0;

	rotateSpeed = 0.01f;
	zoomSpeed = 0.1;
}


orbitCamera::~orbitCamera(void)
{
}

void orbitCamera::draw(void)
{
	glm::quat rotation = glm::quat(glm::vec3(rotY, rotX, 0));
	getParent()->getTrans()->setRotation(rotation);
	getParent()->getTrans()->setPos(rotation * glm::vec3(0.0, 0.0, radius) + center);
}
void orbitCamera::update(void)
{
	bool shiftPressed = input::isKeyPressed(GLFW_KEY_LEFT_SHIFT) || input::isKeyPressed(GLFW_KEY_RIGHT_SHIFT);
	int mult = 1;
	if(shiftPressed) mult *= 10;
	if(input::isKeyPressed(GLFW_KEY_W))
	{
		rotY += rotateSpeed * mult;
	}
	if(input::isKeyPressed(GLFW_KEY_S))
	{
		rotY -= rotateSpeed * mult;
	}
	if(input::isKeyPressed(GLFW_KEY_A))
	{
		rotX += rotateSpeed * mult;
	}
	if(input::isKeyPressed(GLFW_KEY_D))
	{
		rotX -= rotateSpeed * mult;
	}

	if(input::isKeyPressed(GLFW_KEY_Q))
	{
		radius += zoomSpeed * mult;
	}
	if(input::isKeyPressed(GLFW_KEY_E))
	{
		radius -= zoomSpeed * mult;
	}
	//rotY = helper::clamp(rotY, -0.78539816339, 0.78539816339);
}
void orbitCamera::fixedUpdate(void)
{

}
void orbitCamera::destroy(void)
{

}
void orbitCamera::start(void)
{

}