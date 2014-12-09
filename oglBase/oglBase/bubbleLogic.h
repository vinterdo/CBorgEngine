#pragma once
#include "component.h"
#include "gameObject.h"
#include "material.h"
#include "shader.h"
#include "tex2d.h"
#include "mesh.h"
#include "meshRenderer.h"
class bubbleLogic :
	public component
{
public:
	bubbleLogic(void);
	~bubbleLogic(void);

	bool bonus;

	virtual void draw(void)
	{

	}
	virtual void update(void)
	{
	}
	virtual void fixedUpdate(void)
	{
		glm::vec3 pos = getParent()->getTrans()->getPos();

		if(pos.y > 15)
		{
			getParent()->destroy();
		}

		pos.y += 0.05;

		getParent()->getTrans()->setPos(pos);
	}
	virtual void destroy(void)
	{

	}
	virtual void start(void)
	{

	}
};

