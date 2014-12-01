#include "scene.h"

scene::scene()
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
		if(!objects[i]->disabled)
			objects[i]->update();
	}
}

void scene::fixedUpdate()
{
	for(int i =0; i < objects.size(); i++)
	{
		if(!objects[i]->disabled)
			objects[i]->fixedUpdate();
	}
}

void scene::draw()
{
	for(int i =0; i < objects.size(); i++)
	{
		if(!objects[i]->disabled)
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
	objects.push_back(GO);
	GO->start();
}

//============================================