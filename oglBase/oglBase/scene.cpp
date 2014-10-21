#include "scene.h"

scene::scene(void)
{
}

scene::~scene(void)
{
}

//============================================

void scene::start()
{

}

void scene::update()
{
	for(int i =0; i < objects.size(); i++)
	{
		objects[i]->update();
	}
}

void scene::fixedUpdate()
{
	for(int i =0; i < objects.size(); i++)
	{
		objects[i]->fixedUpdate();
	}
}

void scene::draw()
{
	for(int i =0; i < objects.size(); i++)
	{
		objects[i]->draw();
	}
}

void scene::destroy()
{
	for(int i =0; i < objects.size(); i++)
	{
		objects[i]->destroy();
	}
}

void scene::addGO(gameObject* GO)
{
	printf("addedGO");
	objects.push_back(GO);
	GO->start();
}

//============================================