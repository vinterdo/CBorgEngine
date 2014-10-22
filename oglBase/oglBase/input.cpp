#include "input.h"

input::input()
{
	
}

input::~input(void)
{
}

bool input::keyboardState[];

/*
void update(void);
	bool isKeyDown(int key);
	bool isKeyPressed(int key);
	bool isKeyReleased(int key);
	glm::vec2 getMousePos(void);
	bool isLMBDown(void);
	bool isLMBPressed(void);
	bool isLMBReleased(void);
	bool isRMBDown(void);
	bool isRMBPressed(void);
	bool isRMBReleased(void);
*/

void input::update(GLFWwindow* window)
{
	for(int i=0; i< GLFW_KEY_LAST; i++)
	{
		keyboardState[i] = (bool)glfwGetKey(window, i);
	}
}

bool input::isKeyDown(int key)
{
	return keyboardState[key];
}