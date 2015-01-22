#include "mesh.h"


mesh::mesh(void)
{
	mode = GL_TRIANGLES;
}


mesh::~mesh(void)
{
}

bool mesh::load(std::string path)
{
	return load(path, 0);
}

bool mesh::load(std::string path, int modelId)
{
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(path, 0);
	if( !scene)
	{
		fprintf( stderr, importer.GetErrorString());
		getchar();
		return false;
	}
	const aiMesh* mesh = scene->mMeshes[modelId]; 
	
	vertices.reserve(mesh->mNumVertices);
	for(unsigned int i=0; i<mesh->mNumVertices; i++)
	{
		aiVector3D pos = mesh->mVertices[i];
		vertices.push_back(glm::vec3(pos.x, pos.y, pos.z));
	}
	
	uvs.reserve(mesh->mNumVertices);
	for(unsigned int i=0; i<mesh->mNumVertices; i++)
	{
		aiVector3D UVW = mesh->mTextureCoords[0][i]; 
		uvs.push_back(glm::vec2(UVW.x, UVW.y));
	}

	normals.reserve(mesh->mNumVertices);
	for(unsigned int i=0; i<mesh->mNumVertices; i++)
	{
		aiVector3D n = mesh->mNormals[i];
		normals.push_back(glm::vec3(n.x, n.y, n.z));
	}

	indices.reserve(3*mesh->mNumFaces);
	for (unsigned int i=0; i<mesh->mNumFaces; i++)
	{
		indices.push_back(mesh->mFaces[i].mIndices[0]);
		indices.push_back(mesh->mFaces[i].mIndices[1]);
		indices.push_back(mesh->mFaces[i].mIndices[2]);
	}

	indexVBO();
	build();


	return true;
}

void mesh::passVertices(int vertexModelspaceId, int vertexUVId, int normalId)
{
		glEnableVertexAttribArray(vertexModelspaceId);
		glBindBuffer(GL_ARRAY_BUFFER, getVertexBufferId());
		glVertexAttribPointer(vertexModelspaceId, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glEnableVertexAttribArray(vertexUVId);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
		glVertexAttribPointer(vertexUVId, 2, GL_FLOAT ,GL_FALSE, 0, (void*)0 );

		glEnableVertexAttribArray(normalId);
		glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
		glVertexAttribPointer(normalId, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

		glDrawElements(mode, indices.size(), GL_UNSIGNED_INT, (void*)0);

		glDisableVertexAttribArray(vertexModelspaceId);
		glDisableVertexAttribArray(vertexUVId);
		glDisableVertexAttribArray(normalId);
}

int mesh::getVertexBufferId()
{
	return vertexbuffer;
}

int mesh::getUVBufferId()
{
	return uvbuffer;
}

mesh* mesh::loadNew(std::string path)
{
	mesh* m = new mesh();
	m->load(path);
	return m;
}
mesh* mesh::loadNew(std::string path, int modelId)
{
	mesh* m = new mesh();
	m->load(path, modelId);
	return m;
}

bool mesh::getSimilarVertexIndex_fast(PackedVertex & packed, std::map<PackedVertex,unsigned short> & VertexToOutIndex, unsigned short & result)
{
	std::map<PackedVertex,unsigned short>::iterator it = VertexToOutIndex.find(packed);
	if ( it == VertexToOutIndex.end() )
	{
		return false;
	}
	else
	{
		result = it->second;
		return true;
	}
}

void mesh::indexVBO()
{
	std::map<PackedVertex,unsigned short> VertexToOutIndex;

	std::vector<glm::vec3> out_vertices;
	std::vector<glm::vec2> out_uvs;
	std::vector<glm::vec3> out_normals;
	std::vector<unsigned int> out_indices;
	for ( unsigned int i=0; i<vertices.size(); i++ )
	{
		PackedVertex packed = {vertices[i], uvs[i], normals[i]};
		
		unsigned short index;
		bool found = getSimilarVertexIndex_fast( packed, VertexToOutIndex, index);

		if ( found )
		{
			out_indices.push_back( index );
		}
		else
		{ 
			out_vertices.push_back( vertices[i]);
			out_uvs     .push_back( uvs[i]);
			out_normals .push_back( normals[i]);
			unsigned short newindex = (unsigned short)out_vertices.size() - 1;
			out_indices .push_back( newindex );
			VertexToOutIndex[ packed ] = newindex;
		}
	}
	vertices = out_vertices;
	uvs = out_uvs;
	normals = out_normals;
	indices = out_indices;
}

std::vector<mesh*> mesh::loadAllMeshes(std::string path)
{
#pragma message("TODO")
	return std::vector<mesh*>();
}

void mesh::build()
{

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

	glGenBuffers(1, &elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0] , GL_STATIC_DRAW);
}
