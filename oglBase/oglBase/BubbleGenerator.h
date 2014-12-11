#include "component.h"
#include "gameObject.h"
#include "material.h"
#include "shader.h"
#include "tex2d.h"
#include "mesh.h"
#include "meshRenderer.h"
#include "bubbleLogic.h"
#include "pointLight.h"
#include "playerLogic.h"

class bubbleGenerator :
	public component
{
public:
	bubbleGenerator(gameObject* _player)
	{
		player= _player;
	}
	~bubbleGenerator(void);

	std::vector<gameObject*> bubbles;

	int lastTime;
	int interval;
	mesh* sphereMesh;
	shader* bubbleShader;
	shader* bonusShader;
	tex2d* bubbleTex;
	tex2d* bonusTex;

	gameObject* player;
	float speed;

	void generateBubble()
	{
		
		gameObject* go = new gameObject();
		go->getTrans()->setPos(glm::vec3(rand() % 30 - 15, -12, 1));
		go->getTrans()->setScale(glm::vec3(0.5, 0.5, 0.5));
		bubbleLogic* bl = new bubbleLogic(player);
		bl->bonus = rand() % 3;
		bl->speed = speed;
		material* mat = new material();
		if(!(bl->bonus))
		{
			pointLight* pl = new pointLight(glm::vec3(0.1, 0.1, 0.9), 20);
			go->addComponent(pl);
			mat->setShader(bonusShader);
		}
		else
		{
			mat->setShader(bubbleShader);
		}
		go->addComponent(bl);
		meshRenderer* mr = new meshRenderer();
		mr->setMesh(sphereMesh);
		mr->setMat(mat);
		go->addComponent(mr);
		
		getParent()->getParentScene()->addGO(go);
		bubbles.push_back(go);
	}

	virtual void draw(void)
	{

	}
	virtual void update(void)
	{
	}
	virtual void fixedUpdate(void)
	{
		if(lastTime < clock() - interval)
		{
			generateBubble();
			lastTime = clock();
			speed += 0.001;
			player->getComponent<playerLogic*>()->speed += 0.001;
		}
		
	}
	virtual void destroy(void)
	{

	}
	virtual void start(void)
	{
		interval = 400;
		speed = 0.05;
		bubbleTex = new tex2d();
		bubbleTex->load("redPaper.jpg");
		bonusTex = new tex2d();
		bonusTex->load("blueTile.jpg");

		bubbleShader = shader::loadNew("BlinnPhong");
		bonusShader = shader::loadNew("BlinnPhong");

		bubbleShader->setValue("mainTex", new uniformTex2d(bubbleTex));
		bonusShader->setValue("mainTex", new uniformTex2d(bonusTex));

		sphereMesh = mesh::loadNew("sphere.obj", 0);

		srand(time(NULL));
	}
};
