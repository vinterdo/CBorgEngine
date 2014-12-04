#include "tex2d.h"
#include <windows.h>
#include <SOIL.h>

tex2d::tex2d(void)
{
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