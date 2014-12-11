#pragma once
#include "component.h"
#include "gameObject.h"
#include "material.h"
#include "shader.h"
#include "tex2d.h"
#include "mesh.h"
#include "meshRenderer.h"
#include "playerLogic.h"

class bubbleLogic :
	public component
{
public:
	bubbleLogic(gameObject* _player);
	~bubbleLogic(void);

	bool bonus;
	gameObject* player;


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

		if(pos.y > 15)
		{
			getParent()->destroy();
		}

		pos.y += speed;

		getParent()->getTrans()->setPos(pos);

		if(glm::distance(pos, player->getTrans()->getPos()) < 2)
		{
			getParent()->getTrans()->setPos(glm::vec3(0, 100, 0));

			if(!bonus)
			{
				player->getComponent<playerLogic*>()->points += 10;
				printf("%i\n", player->getComponent<playerLogic*>()->points);
			}
			else
			{
				player->getComponent<playerLogic*>()->points = 0;
				printf("%i\n", player->getComponent<playerLogic*>()->points);
			}
		}
	}
	virtual void destroy(void)
	{

	}
	virtual void start(void)
	{

	}
};
