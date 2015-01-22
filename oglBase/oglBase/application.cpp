#include "application.h"

float application::FPS = 0;

application::application(void)
{
	currentScene = NULL;
}

application::~application(void)
{
}

void application::run(void)
{
	float fixTime = 0;
	while(running)
	{
		newTime = clock();
		dt = newTime - time;
		time = newTime;

		++frames;
		FPSTime += dt;
		fixTime += dt; 

		if(fixTime > 1000.0f / currentSettings.getFixedUpdatePS())
		{
			fixTime -= 1000.0f / currentSettings.getFixedUpdatePS();
			fixedUpdate();
		}

		if(FPSTime >= 1000.0f)
		{
			FPS = (frames / FPSTime) * 1000.0f;
			frames = 0;
			FPSTime = 0.0f;
			if(currentSettings.getShowFPS())
			{
				std::stringstream ss;
				ss << currentSettings.getAppName() << " " << FPS;
				glfwSetWindowTitle(window, ss.str().c_str()); 
			}
		}

		update();
		draw();
	}

	destroy();
}

void application::start(void)
{
	initOpenGL();
	running = true;
	currentSettings = settings();

	time = clock();
	FPSTime = 0;
	frames = 0;

	if(currentScene != NULL)
	{
		currentScene->start();
	}
}

void application::update(void)
{
	glfwPollEvents();  
	input::update(window);
	if(glfwWindowShouldClose(window)) stop();

	if(currentScene != NULL)
	{
		currentScene->update();
	}
}

void application::fixedUpdate(void)
{
	if(currentScene != NULL)
	{
		currentScene->fixedUpdate();
	}
}

void application::draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

	if(currentScene != NULL)
	{
		currentScene->draw();
	}

    glfwSwapBuffers(window);  
}

void application::destroy(void)
{
	if(currentScene != NULL)
	{
		currentScene->destroy();
		delete currentScene;
	}
	glfwDestroyWindow(window);  
    glfwTerminate();  
	exit(EXIT_SUCCESS);  
}

void application::stop(void)
{
	running = false;
}

//===============================================

static void error_callback(int error, const char* description)  
{  
    fputs(description, stderr);  
    _fgetchar();  
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)  
{  
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)  
    glfwSetWindowShouldClose(window, GL_TRUE);  
}  

// ===============================================

void application::initOpenGL(void)
{
	glfwSetErrorCallback(error_callback);  
  
    if (!glfwInit())  
    {  
        exit(EXIT_FAILURE);  
    }  
	/*
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Request a specific OpenGL version  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //Request a specific OpenGL version  
    glfwWindowHint(GLFW_SAMPLES, 4); //Request 4x antialiasing  
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
	*/
	window = glfwCreateWindow(currentSettings.getResX(), currentSettings.getResY(), currentSettings.getAppName().c_str(), NULL, NULL);  
    if (!window)  
    {  
        fprintf(stderr, "Failed to open GLFW window.\n" );  
        glfwTerminate();  
        exit(EXIT_FAILURE);  
    }    

    glfwMakeContextCurrent(window);  
    glfwSetKeyCallback(window, key_callback);  
    GLenum err = glewInit();  
    if (err != GLEW_OK)   
    {  
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));  
		stop();
    }  
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  

	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS); 

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);
}

//===============================================

void application::setScene(scene* s)
{
	currentScene = s;
}

float application::getFPS()
{
	return FPS;
}
