#include "lodManager.h"
#include "input.h"
#include "application.h"

lodManager::lodManager(std::string path)
{
	current = 0;
	automode = false;

	for(int i =0; i <9; i++)
	{
		gameObject* go = new gameObject();
		terrain* t = new terrain(i + 1);
		t->load(path);
		go->addComponent(t);
		terrains.push_back(go);

		go->disabled = true;
	}

	terrains[current]->disabled = false;
}


lodManager::~lodManager(void)
{
}

void lodManager::draw(void)
{
	terrains[current]->draw();
}
void lodManager::update(void)
{
	terrains[current]->update();

	if(input::isKeyDown(GLFW_KEY_0))
	{
		automode = !automode;
	}

	if(!automode)
	{
		for(int i=GLFW_KEY_1; i <= GLFW_KEY_9 ; i++)
		{
			if(input::isKeyDown(i))
			{
				terrains[current]->disabled = true;
				current = i - GLFW_KEY_1;
				terrains[current]->disabled = false;
			}
		}
	}
	else
	{
		if(application::getFPS() < 10)
		{
			terrains[current]->disabled = true;
			current++;
			if(current > 9) current = 9;
			terrains[current]->disabled = false;
		}
		if(application::getFPS() > 10)
		{
			terrains[current]->disabled = true;
			current--;
			if(current < 1) current = 1;
			terrains[current]->disabled = false;
		}
	}
}
void lodManager::fixedUpdate(void)
{
	terrains[current]->fixedUpdate();

}
void lodManager::destroy(void)
{
	for(int i =0; i <9; i++)
	{
		terrains[i]->destroy();
	}
}
void lodManager::start(void)
{
	for(int i =0; i <9; i++)
	{
		terrains[i]->start();
	}
}