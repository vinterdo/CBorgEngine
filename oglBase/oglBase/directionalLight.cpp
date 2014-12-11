#include "directionalLight.h"


std::vector<directionalLight*> directionalLight::directionalLights;

directionalLight::directionalLight(glm::vec3 color, glm::vec3 direction, float power)  : light(color, power)
{

}


directionalLight::~directionalLight(void)
{
}


void directionalLight::draw(void)
{
}

void directionalLight::start(void)
{

}

void directionalLight::update(void)
{
}

void directionalLight::fixedUpdate(void)
{
}

void directionalLight::destroy(void)
{
	for(int i=0; i < directionalLights.size(); i++)
	{
		if(directionalLights[i] == this)
		{
			directionalLights.erase(directionalLights.begin() + i);
			break;
		}
	}
}