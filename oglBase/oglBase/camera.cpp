#include "camera.h"
camera* camera::mainCamera = NULL;

camera::camera(void)
{
	if(mainCamera == NULL)
	{
		mainCamera = this;
	}
}


camera::~camera(void)
{
	setViewLookAt(glm::vec3(0,0,0), glm::vec3(0,1,0)); 
}

void camera::draw(void)
{
}
void camera::update(void)
{
}
void camera::fixedUpdate(void)
{
}
void camera::destroy(void)
{
}
void camera::start(void)
{
}

void camera::setProjectionOrtho(float left, float right, float bottom, float top)
{
	projection = glm::ortho(left, right, bottom, top, float(0), float(1000));
}
void camera::setProjectionPerspective(float fov, float width, float height, float near, float far)
{
	projection = glm::perspectiveFov(fov, width, height, near, far);
}
void camera::setProjection(glm::mat4 proj)
{
	projection = proj;
}

void camera::setViewLookAt(glm::vec3 target, glm::vec3 up)
{	
	//view = glm::lookAt(getParent()->getTrans()->getPos(), target, up);
}
void camera::setView(glm::mat4 v)
{
	//view = v;
}

glm::mat4 camera::getProjView()
{
	return getProj() * getView() ;
}
glm::mat4 camera::getProj()
{
	return projection;
}
glm::mat4 camera::getView()
{
	return glm::lookAt(getParent()->getTrans()->getPos(), getParent()->getTrans()->getPos() + glm::rotate(getParent()->getTrans()->getRotation(),glm::vec3(0,0,-1)), glm::vec3(0,1,0));
	//return view;
}

