#include "gameObject.h"


gameObject::gameObject(void)
{
}


gameObject::~gameObject(void)
{
}

void gameObject::draw(void)
{
}

void gameObject::start(void)
{
}

void gameObject::update(void)
{
}

void gameObject::fixedUpdate(void)
{
}

void gameObject::destroy(void)
{
}

transform gameObject::getTrans(void)
{
	return trans;
}

void gameObject::setTrans(transform t)
{
	trans = t;
}