#include "input.h"

input::input()
{
	
}

input::~input(void)
{
}

bool input::kbState[];
bool input::oldKbState[];

/*
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
		oldKbState[i] = kbState[i];
		kbState[i] = (bool)glfwGetKey(window, i);
	}
}

bool input::isKeyDown(int key)
{
	return kbState[key] && !oldKbState[key];
}

bool input::isKeyPressed(int key)
{
	return kbState[key];
}

bool input::isKeyReleased(int key)
{
	return !kbState[key] && oldKbState[key];
}