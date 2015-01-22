#include "tex2d.h"
#include <SOIL.h>
#include <GL/glew.h>  
#include <GLFW/glfw3.h>  

tex2d::tex2d(void)
{
	texId = 0;
}


tex2d::~tex2d(void)
{
}


bool tex2d::load(std::string path)
{
	if(texId == 0)
	{
		texId = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	}
	else
	{
		SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, texId, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	}

	if(texId == 0)
	{
		printf("Texture loading error: '%s'\n", SOIL_last_result());
	}
	return true;
}

int tex2d::getId()
{
	return texId;
}

int tex2d::getSizeX()
{
	int w;
	glBindTexture(GL_TEXTURE_2D, texId);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w);
	return w;
}

int tex2d::getSizeY()
{
	int h;
	glBindTexture(GL_TEXTURE_2D, texId);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h);
	return h;
}