#include "material.h"
#include "shader.h"
#include <glm.hpp>

material::material(void)
{
}


material::~material(void)
{
}

bool material::load(std::string path)
{
	programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );
	return true;
}

void material::begin()
{
	glUseProgram(programID);
	int colorID = glGetUniformLocation(programID, "cardColor");
	glUniform3fv(colorID, 1, &glm::vec3(0,1,0)[0]);
}

void material::end()
{
	glUseProgram(0);
}