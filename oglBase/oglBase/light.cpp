#include "light.h"
#include "transform.h"
#include "gameObject.h"

std::vector<light*> light::lightList;

light::light(glm::vec3 color, float power)
{
	setColor(color);
	setPower(power);
	lightList.push_back(this);
}


light::~light(void)
{
}


float light::getPower()
{
	return power;
}
glm::vec3 light::getColor()
{
	return color;
}
glm::vec3 light::getPos()
{
	return getParent()->getTrans()->getPos();
}
void light::setPower(float p)
{
	power = p;
}
void light::setColor(glm::vec3 col)
{
	color = col;
}


void light::draw(void)
{
}

void light::start(void)
{
	
}

void light::update(void)
{
}

void light::fixedUpdate(void)
{
}

void light::destroy(void)
{
}