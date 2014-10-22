#pragma once

#include <GL/glew.h>  
#include <GLFW/glfw3.h>  
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>
#include <sstream>
#include <glm.hpp>

#include "settings.h"
#include "scene.h"
#include "input.h"

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


	void setScene(scene* s);

private:
	bool running;
	GLFWwindow* window;
	settings currentSettings;

	clock_t time, newTime, dt;
	float FPS, FPSTime;
	unsigned frames;

	scene* currentScene;

	
	void initOpenGL(void);
};

