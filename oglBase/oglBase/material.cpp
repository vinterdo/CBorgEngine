#include "material.h"
#include "shader_tmp.h"
#include <glm.hpp>

material::material(void)
{
}


material::~material(void)
{
}

bool material::load(std::string path)
{
	//programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );
	return true;
}

void material::begin()
{
	sh->setValue("color", glm::vec3(1,0,1));
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