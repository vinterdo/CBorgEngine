#include "terrain.h"
#include "helper.h"
#include <fstream>
#include <iostream>

terrain::terrain(void)
{
	heightmap = NULL;
	terrainMesh = NULL;
	mr = NULL;
	lod = 1;
}

terrain::terrain(int _lod)
{
	heightmap = NULL;
	terrainMesh = NULL;
	mr = NULL;
	lod = _lod;
}

terrain::~terrain(void)
{
}

bool terrain::load(std::string path)
{
	if(heightmap != NULL)
	{
		delete heightmap;
	}
	if(terrainMesh != NULL)
	{
		delete terrainMesh;
	}
	if(mr != NULL)
	{
		delete mr;
	}

	if(helper::getExtension(path) == "hgt" || helper::getExtension(path) == "HGT")
	{
		getDataFromHGT(path);
	}
	else
	{
		getDataFromHeightmap(path);
	}

	terrainMesh = new mesh();
	terrainMesh->vertices = getVertices();
	terrainMesh->indices = getIndices();
	terrainMesh->uvs = std::vector<glm::vec2>(1);
	terrainMesh->normals = std::vector<glm::vec3>(1);
	terrainMesh->mode = GL_TRIANGLE_STRIP;

	terrainMesh->build();

	material* mat = new material();
	shader* sh = new shader();
	sh->load("TerrainHeightShader");
	mat->setShader(sh);

	mr = new meshRenderer();
	mr->setMesh(terrainMesh);
	mr->setMat(mat);

	return true;
}

void terrain::draw(void)
{
	if(mr != NULL)
		mr->draw();
}
void terrain::update(void)
{
	if(mr != NULL)
		mr->update();
}
void terrain::fixedUpdate(void)
{
	if(mr != NULL)
		mr->fixedUpdate();
}
void terrain::destroy(void)
{
	if(mr != NULL)
		mr->destroy();
}
void terrain::start(void)
{
	if(mr != NULL)
		mr->start();
}

int terrain::getIndicesCount()
{
	return (width*height) + (width-1)*(height-2);
}

std::vector<glm::vec3> terrain::getVertices()
{
	const int SRTM_SIZE = 1201;

	std::vector<glm::vec3> vertices = std::vector<glm::vec3>(getVerticesCount());
	int i = 0;

	for ( int row=0; row<height; row++ ) 
	{
		for ( int col=0; col<width; col++ ) 
		{
			vertices[i] = glm::vec3(col * lod, data[(col * lod) + (row * lod) * SRTM_SIZE], row * lod);
			i++;
		}
	}
	return vertices;
}

std::vector<unsigned int> terrain::getIndices()
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

int terrain::getVerticesCount()
{
	return width * height * 3 ;
}

void terrain::getDataFromHeightmap(std::string path)
{
	heightmap = new tex2d();
	heightmap->load(path);

	width = heightmap->getSizeX();
	height = heightmap->getSizeY();

	int size = width * height;
	data = std::vector<unsigned short>(size);

	glGetTexImage(GL_TEXTURE_2D, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, &(data[0]));
}

void terrain::getDataFromHGT(std::string path)
{
	const int SRTM_SIZE = 1201;
	data = std::vector<unsigned short>(SRTM_SIZE * SRTM_SIZE);

	std::ifstream file(path, std::ios::in|std::ios::binary);
	if(!file)
	{
		std::cout << "Error opening file!" << std::endl;
	}

	width = SRTM_SIZE / lod;
	height = SRTM_SIZE / lod;

	unsigned char buffer[2];
	for (int i = 0; i < SRTM_SIZE; ++i)
	{
		for (int j = 0; j < SRTM_SIZE; ++j) 
		{
			if(!file.read( reinterpret_cast<char*>(buffer), sizeof(buffer) ))
			{
				std::cout << "Error reading file!" << std::endl;
			}
			data[i * SRTM_SIZE + j] = ((buffer[0] << 8) | buffer[1]) / 10;
		}
	}
}

void terrain::setParent(gameObject* go)
{
	parent = go;
	if(mr != NULL)
	{
		mr->setParent(go);
	}
}