#pragma once

#include <GL/glew.h>  
#include <GLFW/glfw3.h>  
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>
#include <sstream>
#include <vector>
#include "transform.h"
#include "component.h"

class gameObject
{
public:
	gameObject(void);
	~gameObject(void);

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);
	
	transform* getTrans(void);
	void setTrans(transform t);
	bool disabled;

private:
	transform trans;
	std::vector<component*> components;
};

