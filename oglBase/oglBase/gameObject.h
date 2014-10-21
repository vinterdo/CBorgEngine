#include <GL/glew.h>  
#include <GLFW/glfw3.h>  
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>
#include <sstream>

#pragma once
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
};

