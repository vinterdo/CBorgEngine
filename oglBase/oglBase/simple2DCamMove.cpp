#include "simple2DCamMove.h"
#include "input.h"
#include "gameObject.h"

simple2DCamMove::simple2DCamMove(void)
{
	speed = 0.07;
}


simple2DCamMove::~simple2DCamMove(void)
{
}

void simple2DCamMove::draw(void)
{
}
void simple2DCamMove::update(void)
{
}
void simple2DCamMove::fixedUpdate(void)
{
	
	if(input::isKeyPressed(GLFW_KEY_W))
	{
		getParent()->getTrans()->setPos(getParent()->getTrans()->getPos() + glm::vec3(0, 0, -speed));
	}
	if(input::isKeyPressed(GLFW_KEY_S))
	{
		getParent()->getTrans()->setPos(getParent()->getTrans()->getPos() + glm::vec3(0, 0, +speed));
	}

	if(input::isKeyPressed(GLFW_KEY_A))
	{
		getParent()->getTrans()->setPos(getParent()->getTrans()->getPos() + glm::vec3(-speed, 0, 0));
	}
	if(input::isKeyPressed(GLFW_KEY_D))
	{
		getParent()->getTrans()->setPos(getParent()->getTrans()->getPos() + glm::vec3(speed, 0, 0));
	}

	if(input::isKeyPressed(GLFW_KEY_LEFT_SHIFT))
	{
		getParent()->getTrans()->setPos(getParent()->getTrans()->getPos() + glm::vec3(0,-speed, 0));
	}
	if(input::isKeyPressed(GLFW_KEY_SPACE))
	{
		getParent()->getTrans()->setPos(getParent()->getTrans()->getPos() + glm::vec3(0, speed, 0));
	}

	if(input::isKeyPressed(GLFW_KEY_RIGHT))
	{
		glm::vec3 angles = glm::eulerAngles(getParent()->getTrans()->getRotation());
		angles.x += speed;
		getParent()->getTrans()->setRotation(glm::quat(angles));
	}
	if(input::isKeyPressed(GLFW_KEY_LEFT))
	{
		
		glm::vec3 angles = glm::eulerAngles(getParent()->getTrans()->getRotation());
		angles.x -= speed;
		getParent()->getTrans()->setRotation(glm::quat(angles));
	}
}
void simple2DCamMove::destroy(void)
{
}
void simple2DCamMove::start(void)
{
}
