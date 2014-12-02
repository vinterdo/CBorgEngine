#include "meshRenderer.h"
#include "uniformValue.h"
#include "camera.h"

meshRenderer::meshRenderer(void)
{
}

meshRenderer::~meshRenderer(void)
{
}


void meshRenderer::draw(void)
{
	mat->begin();
	mat->setValue("MVP", new uniformMat4(camera::mainCamera->getProjView() * getParent()->getTrans()->getModelMatrix()));
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