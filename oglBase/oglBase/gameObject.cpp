#include "gameObject.h"


gameObject::gameObject(void)
{
	disabled = false;
}


gameObject::~gameObject(void)
{
}

void gameObject::draw(void)
{
	for(int i=0; i<components.size(); i++)
	{
		components[i]->draw();
	}
}

void gameObject::start(void)
{
	for(int i=0; i<components.size(); i++)
	{
		components[i]->start();
	}
}

void gameObject::update(void)
{
	for(int i=0; i<components.size(); i++)
	{
		components[i]->update();
	}
}

void gameObject::fixedUpdate(void)
{
	for(int i=0; i<components.size(); i++)
	{
		components[i]->fixedUpdate();
	}
}

void gameObject::destroy(void)
{
	for(int i=0; i<components.size(); i++)
	{
		components[i]->destroy();
	}
}

transform gameObject::getTrans(void)
{
	return trans;
}

void gameObject::setTrans(transform t)
{
	trans = t;
}