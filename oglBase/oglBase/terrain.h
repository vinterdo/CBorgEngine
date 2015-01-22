#pragma once
#include "component.h"
#include <string>
#include "tex2d.h"
#include "mesh.h"
#include "meshRenderer.h"
#include <vector>
class terrain :
	public component
{
public:
	terrain(void);
	terrain(int _lod);
	~terrain(void);

	virtual bool load(std::string path);

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);

	mesh* terrainMesh;
	meshRenderer* mr;

	virtual void setParent(gameObject* go);

private:

	tex2d* heightmap;
	std::vector<unsigned short> data;
	int width;
	int height;
	int lod;

	int getVerticesCount();
	int getIndicesCount();
	std::vector<glm::vec3> getVertices();
	std::vector<unsigned int> getIndices();
	void getDataFromHGT(std::string path);
	void getDataFromHeightmap(std::string path);
};

