#pragma once
#include "component.h"
#include "gameObject.h"
#include "material.h"
#include "shader.h"
#include "tex2d.h"
#include "mesh.h"
#include "meshRenderer.h"
#include "pointLight.h"
#include "input.h"
#include "camera.h"
class playerLogic : public component
{
public:
	playerLogic(gameObject* _tpCam, gameObject* _sideCam);
	~playerLogic(void);

	float speed;
	gameObject* tpCam;
	gameObject* sideCam;

	bool camMode; // false for tp, true for side

	static int points;
	int fov;

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

		if(input::isKeyDown(GLFW_KEY_TAB))
		{
			if(camMode)
			{
				camera::mainCamera = sideCam->getComponent<camera*>();
				camMode = false;
			}
			else
			{
				camera::mainCamera = tpCam->getComponent<camera*>();
				camMode = true;
			}
		}

		if(input::isKeyPressed(GLFW_KEY_Z) && fov > 30)
		{
			fov--;
			tpCam->getComponent<camera*>()->setProjectionPerspective(fov, 4,3, 0.1, 500);
			sideCam->getComponent<camera*>()->setProjectionPerspective(fov, 4,3, 0.1, 500);
		}
		if(input::isKeyPressed(GLFW_KEY_X) && fov < 60)
		{
			fov++;
			tpCam->getComponent<camera*>()->setProjectionPerspective(fov, 4,3, 0.1, 500);
			sideCam->getComponent<camera*>()->setProjectionPerspective(fov, 4,3, 0.1, 500);
		}

		getParent()->getTrans()->setPos(pos);
		tpCam->getTrans()->setPos(pos - glm::vec3(2, -1, 0));
	}
	virtual void destroy(void)
	{

	}
	virtual void start(void)
	{
		speed = 0.05;
		fov = 45;
	}
};

