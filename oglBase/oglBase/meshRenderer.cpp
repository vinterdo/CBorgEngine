#include "meshRenderer.h"


meshRenderer::meshRenderer(void)
{
}


meshRenderer::~meshRenderer(void)
{
}

void meshRenderer::draw(void)
{
	mat->begin();
	m->passVertices();
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