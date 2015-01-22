#include "terrainSpherical.h"
#include "helper.h"
#include <fstream>
#include <iostream>
#include <cmath>

#define M_PI 3.141592653
#define M_PI_2 3.141592653/2

terrainSpherical::terrainSpherical(float _radius)
{
	radius = _radius;
	heightmap = NULL;
	terrainMesh = NULL;
	terrainMeshRenderer = NULL;
	sphere = new spherePrimitive(radius, 72, 36);
	sphereRenderer = new meshRenderer();
	material* mat = new material();
	shader* sh = new shader();
	sh->load("SingleColor");
	sh->setValue("color", new uniformVector3(glm::vec3(0,0,1)));
	mat->setShader(sh);
	sphereRenderer->setMesh(sphere);
	sphereRenderer->setMat(mat);
}

terrainSpherical::~terrainSpherical(void)
{
}

bool terrainSpherical::load(std::string path)
{
	if(heightmap != NULL)
	{
		delete heightmap;
	}
	if(terrainMesh != NULL)
	{
		delete terrainMesh;
	}

	if(helper::getExtension(path) == "hgt" || helper::getExtension(path) == "HGT")
	{
		getDataFromHGT(path);
	}
	else
	{
		getDataFromHeightmap(path);
	}

	assignGlobalPosition(path);

	terrainMesh = new mesh();
	terrainMesh->vertices = getVertices();
	terrainMesh->indices = getIndices();
	terrainMesh->uvs = std::vector<glm::vec2>(1);
	terrainMesh->normals = std::vector<glm::vec3>(1);
	terrainMesh->mode = GL_TRIANGLE_STRIP;

	terrainMesh->build();

	material* mat = new material();
	shader* sh = new shader();
	sh->load("TerrainSpherical");
	sh->setValue("radius", new uniformFloat(radius));
	mat->setShader(sh);

	terrainMeshRenderer = new meshRenderer();
	terrainMeshRenderer->setMesh(terrainMesh);
	terrainMeshRenderer->setMat(mat);

	return true;
}

void terrainSpherical::draw(void)
{
	if(terrainMeshRenderer != NULL)
		terrainMeshRenderer->draw();
	sphereRenderer->draw();
}
void terrainSpherical::update(void)
{
	sphereRenderer->update();
}
void terrainSpherical::fixedUpdate(void)
{
	sphereRenderer->fixedUpdate();
}
void terrainSpherical::destroy(void)
{
	sphereRenderer->destroy();
}
void terrainSpherical::start(void)
{
	sphereRenderer->start();
}

int terrainSpherical::getIndicesCount()
{
	return (width*height) + (width-1)*(height-2);
}

std::vector<glm::vec3> terrainSpherical::getVertices()
{
	std::vector<glm::vec3> vertices = std::vector<glm::vec3>(getVerticesCount());
	int i = 0;
	const int SRTM_SIZE = 1201;

	float const R = 1./(float)((SRTM_SIZE -1) * 180);
	float const S = 1./(float)((SRTM_SIZE -1) * 360);

	float offR = (SRTM_SIZE -1) * (globalPosY + 90);
	float offS = (SRTM_SIZE -1) * (globalPosX + 180);

	for ( int r=0; r<height; r++ ) 
	{
		for ( int s=0; s<width; s++ ) 
		{
			float const y = sin( -M_PI_2 + M_PI * (r * R + offR * R));
			float const x = cos(2*M_PI * (s * S + offS * S)) * sin( M_PI * (r * R  + offR * R));
			float const z = sin(2*M_PI * (s * S + offS * S)) * sin( M_PI * (r * R  + offR * R));

			//vertices[i] = glm::vec3(col, data[col + row * width], row);
			vertices[i] = glm::vec3(x, y, z) * (radius + 1 + (float)data[s + r * width] / (float)200);
			i++;
		}
	}
	return vertices;
}

std::vector<unsigned int> terrainSpherical::getIndices()
{
	std::vector<unsigned int> indices = std::vector<unsigned int>(getIndicesCount());
	int i = 0;

	for ( int row=0; row<height-1; row++ ) 
	{
		if ( (row&1)==0 ) 
		{ // even rows
			for ( int col=0; col<width; col++ ) 
			{
				indices[i++] = col + row * width;
				indices[i++] = col + (row+1) * width;
			}
		} 
		else 
		{ // odd rows
			for ( int col=width-1; col>0; col-- )
			{
				indices[i++] = col + (row+1) * width;
				indices[i++] = col - 1 + + row * width;
			}
		}
	}
	if ( (height&1) && height>2 )
	{
		indices[i++] = (height-1) * width;
	}

	return indices;
}

int terrainSpherical::getVerticesCount()
{
	return width * height * 3;
}

void terrainSpherical::getDataFromHeightmap(std::string path)
{
	heightmap = new tex2d();
	heightmap->load(path);

	width = heightmap->getSizeX();
	height = heightmap->getSizeY();

	int size = width * height;
	data = std::vector<unsigned short>(size);

	glGetTexImage(GL_TEXTURE_2D, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, &(data[0]));
}

void terrainSpherical::getDataFromHGT(std::string path)
{
	const int SRTM_SIZE = 1201;
	data = std::vector<unsigned short>(SRTM_SIZE * SRTM_SIZE);

	std::ifstream file(path, std::ios::in|std::ios::binary);
	if(!file)
	{
		std::cout << "Error opening file!" << std::endl;
	}

	width = SRTM_SIZE;
	height = SRTM_SIZE;

	unsigned char buffer[2];
	for (int i = 0; i < SRTM_SIZE; ++i)
	{
		for (int j = 0; j < SRTM_SIZE; ++j) 
		{
			if(!file.read( reinterpret_cast<char*>(buffer), sizeof(buffer) ))
			{
				std::cout << "Error reading file!" << std::endl;
			}
			data[i * width + j] = ((buffer[0] << 8) | buffer[1]) / 10;
		}
	}
}


void terrainSpherical::setParent(gameObject* go)
{
	parent = go;
	sphereRenderer->setParent(go);
	if(terrainMeshRenderer != NULL)
	{
		terrainMeshRenderer->setParent(go);
	}
}

void terrainSpherical::assignGlobalPosition(std::string path)
{
	globalPosY = atoi(helper::getFileName(path).substr(1,2).c_str());
	globalPosX = atoi(helper::getFileName(path).substr(4,6).c_str());
	if(helper::getFileName(path)[0] == 'S' || helper::getFileName(path)[0] == 's')
	{
		globalPosY *= -1;
	}
	if(helper::getFileName(path)[3] == 'W' || helper::getFileName(path)[3] == 'w')
	{
		globalPosX *= -1;
	}
}
