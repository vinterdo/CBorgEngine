#pragma once

#include <GL/glew.h>  
#include <GLFW/glfw3.h>  
#include <stdio.h>  
#include <stdlib.h> 

#include "settings.h"

class application
{
public:
	application(void);
	~application(void);

	void run(void);
	void start(void);
	void update(void);
	void fixedUpdate(void);
	void draw(void);
	void destroy(void);
	void stop(void);

private:
	bool running;
	GLFWwindow* window;
	settings currentSettings;

	void initOpenGL(void);
};

