#pragma once
#include "component.h"
#include "gameObject.h"
#include "material.h"
#include "shader.h"
#include "tex2d.h"
#include "mesh.h"
#include "meshRenderer.h"
#include "bubbleLogic.h"
#include "pointLight.h"
#include "input.h"
class playerLogic : public component
{
public:
	playerLogic(void);
	~playerLogic(void);

	float speed;

	virtual void draw(void)
	{

	}
	virtual void update(void)
	{
	}
	virtual void fixedUpdate(void)
	{
		glm::vec3 pos = getParent()->getTrans()->getPos();
		if(input::isKeyPressed(GLFW_KEY_W) && pos.y < 8.1)
		{
			pos += glm::vec3(0,+speed, 0);
		}
		if(input::isKeyPressed(GLFW_KEY_S) && pos.y > -8.1)
		{
			pos += glm::vec3(0,-speed, 0);
		}

		if(input::isKeyPressed(GLFW_KEY_D) && pos.x < 18.1)
		{
			pos += glm::vec3(+speed, 0, 0);
		}
		if(input::isKeyPressed(GLFW_KEY_A) && pos.x > -18.1)
		{
			pos += glm::vec3(-speed, 0, 0);
		}

		getParent()->getTrans()->setPos(pos);
	}
	virtual void destroy(void)
	{

	}
	virtual void start(void)
	{
		speed = 0.05;
	}
};

