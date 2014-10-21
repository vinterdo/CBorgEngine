#pragma once
#include "gameobject.h"
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

private:
	GLuint programID;
	GLuint vertexbuffer;
	GLuint vertexPosition_modelspaceID;

};

