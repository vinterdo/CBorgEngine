#pragma once
#include "gameobject.h"
#include "transform.h"
#include "shader.h"
#include <gtc/matrix_transform.hpp>

class testGO :
	public gameObject
{
public:
	testGO(void);
	~testGO(void);

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);

	glm::vec3 color;
	shader* sh;

private:
	//GLuint programID;
	GLuint vertexbuffer;
	GLuint vertexPosition_modelspaceID;

	glm::mat4 MVP;
	GLuint MatrixID;
};

