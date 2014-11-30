#include "meshRenderer.h"


meshRenderer::meshRenderer(void)
{
}

meshRenderer::~meshRenderer(void)
{
}


void meshRenderer::draw(void)
{
	glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f);
	glm::mat4 View       = glm::lookAt(
								glm::vec3(0,0,3), 
								glm::vec3(0,0,0),
								glm::vec3(0,1,0) 
						   );
	glm::mat4 MVP        = Projection * View; 

	mat->begin();
	mat->setValue("MVP", &(MVP * getParent()->getTrans()->getModelMatrix()));
	m->passVertices(mat->getVertexModelspaceId());
	mat->end();
}

void meshRenderer::start(void)
{
	
}

void meshRenderer::update(void)
{
}

void meshRenderer::fixedUpdate(void)
{
}

void meshRenderer::destroy(void)
{
}

void meshRenderer::setMesh(mesh* _m)
{
	m = _m;
}

void meshRenderer::setMat(material* _m)
{
	mat = _m;
}