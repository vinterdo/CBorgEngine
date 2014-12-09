#include "meshRenderer.h"
#include "uniformValue.h"
#include "camera.h"
#include "pointLight.h"

meshRenderer::meshRenderer(void)
{
}

meshRenderer::~meshRenderer(void)
{
}


void meshRenderer::draw(void)
{
	mat->begin();
	mat->setValue("M", new uniformMat4(getParent()->getTrans()->getModelMatrix()));
	mat->setValue("V", new uniformMat4(camera::mainCamera->getView()));
	mat->setValue("P", new uniformMat4(camera::mainCamera->getProj()));
	mat->setValue("MVP", new uniformMat4(camera::mainCamera->getProjView() * getParent()->getTrans()->getModelMatrix()));
	pointLight::passPointLights(mat->getShader()->getUniformId("pointLPos"), mat->getShader()->getUniformId("pointLCol"), mat->getShader()->getUniformId("pointLPow"));
	m->passVertices(mat->getVertexModelspaceId(), mat->getVertexUvId(), mat->getNormalsId());
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