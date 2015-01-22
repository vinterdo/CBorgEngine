#pragma once
#include <glm.hpp>
#include <vector>
#include <GL/glew.h>
#include <map>
#include "asset.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct PackedVertex
{
	glm::vec3 position;
	glm::vec2 uv;
	glm::vec3 normal;
	bool operator<(const PackedVertex that) const
	{
		return memcmp((void*)this, (void*)&that, sizeof(PackedVertex))>0;
	};
};

class mesh : public asset
{
public:
	mesh(void);
	~mesh(void);

	void passVertices(int vertexModelspaceId, int vertexUVId, int normalId);
	virtual bool load(std::string path);
	virtual bool load(std::string path, int modelId);

	void build();

	int getVertexBufferId();
	int getUVBufferId();
	static mesh* loadNew(std::string path);
	static mesh* loadNew(std::string path, int modelId);
	static std::vector<mesh*> loadAllMeshes(std::string path);

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	std::vector<unsigned int> indices;

	GLenum mode;

private:
	
	void indexVBO();
	bool getSimilarVertexIndex_fast(PackedVertex & packed, std::map<PackedVertex,unsigned short> & VertexToOutIndex, unsigned short & result);

	unsigned int vertexbuffer;
	unsigned int uvbuffer;
	unsigned int normalbuffer;
	unsigned int elementbuffer;


};

