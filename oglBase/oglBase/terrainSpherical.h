#pragma once
#include "component.h"
#include <string>
#include "tex2d.h"
#include "mesh.h"
#include "meshRenderer.h"
#include <vector>
#include "spherePrimitive.h"

class terrainSpherical : public component
{
public:
	terrainSpherical(float);
	~terrainSpherical(void);

	virtual bool load(std::string path);

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);

	virtual void setParent(gameObject* go);

private:
	tex2d* heightmap;
	std::vector<unsigned short> data;
	int width;
	int height;

	int getVerticesCount();
	int getIndicesCount();
	std::vector<glm::vec3> getVertices();
	std::vector<unsigned int> getIndices();
	void getDataFromHGT(std::string path);
	void getDataFromHeightmap(std::string path);
	void assignGlobalPosition(std::string path);

	spherePrimitive* sphere;
	meshRenderer* sphereRenderer;

	mesh* terrainMesh;
	meshRenderer* terrainMeshRenderer;

	int globalPosX;
	int globalPosY;

	float radius;
};

