#include "material.h"
#include <glm.hpp>

material::material(void)
{
}


material::~material(void)
{
}

bool material::load(std::string path)
{
	return true;
}

void material::begin()
{
	sh->start();
}

void material::end()
{
	sh->end();
}

void material::setShader(shader* _sh)
{
	sh = _sh;
}

int material::getVertexModelspaceId()
{
	return sh->getAttribId("vertexPosition_modelspace");
}

int material::getVertexUvId()
{
	return sh->getAttribId("vertexUV");
}