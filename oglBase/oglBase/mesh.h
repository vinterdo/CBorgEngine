#pragma once
#include <glm.hpp>
#include <vector>
#include <GL/glew.h>
#include "asset.h"

class mesh : public asset
{
public:
	mesh(void);
	~mesh(void);

	void passVertices(int vertexModelspaceId);
	virtual bool load(std::string path);
	int getVertexBufferId();
	int getUVBufferId();
	static mesh* loadNew(std::string path);

private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	
	unsigned int vertexbuffer;
	unsigned int uvbuffer;
};

