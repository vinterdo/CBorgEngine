#include "component.h"


component::component(void)
{
}


component::~component(void)
{
}


gameObject* component::getParent()
{
	return parent;
}

void component::setParent(gameObject* go)
{
	parent = go;
}