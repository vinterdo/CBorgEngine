#pragma once
#include "component.h"
#include "gameObject.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class camera :
	public component
{
public:
	camera(void);
	~camera(void);

	static camera* mainCamera;

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);

	void setProjectionOrtho(float left, float right, float bottom, float top);
	void setProjectionPerspective(float fov, float width, float height, float near, float far);
	void setProjection(glm::mat4);

	glm::mat4 getProjView();
	glm::mat4 getProj();
	glm::mat4 getView();

private:
	glm::mat4 projection;
	//glm::mat4 view;
};

