#include "pointLight.h"
#include "transform.h"
#include "gameObject.h"

std::vector<pointLight*> pointLight::pointLights;

pointLight::pointLight(glm::vec3 color, float power) : light(color, power)
{
	pointLights.push_back(this);
}

pointLight::~pointLight(void)
{
}

void pointLight::passPointLights(int posLocation, int colorLocation, int powerLocation)
{
	if(pointLights.size() > 0)
	{
		std::vector<glm::vec3> positions;
		std::vector<glm::vec3> colors;
		std::vector<float> powers;

		for(int i =0; i< pointLights.size(); i++)
		{
			positions.push_back(pointLights[i]->getParent()->getTrans()->getPos());
			colors.push_back(pointLights[i]->getColor());
			powers.push_back(pointLights[i]->getPower());
		}

		glUniform3fv(posLocation, pointLights.size(), &positions[0][0]);
		glUniform3fv(colorLocation, pointLights.size(), &colors[0][0]);
		glUniform1fv(powerLocation, pointLights.size(), &powers[0]);
	}
}


void pointLight::draw(void)
{
}

void pointLight::start(void)
{
	
}

void pointLight::update(void)
{
}

void pointLight::fixedUpdate(void)
{
}

void pointLight::destroy(void)
{
	for(int i=0; i < pointLights.size(); i++)
	{
		if(pointLights[i] == this)
		{
			pointLights.erase(pointLights.begin() + i);
			break;
		}
	}
}