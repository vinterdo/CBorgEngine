#pragma once
#include <glm.hpp>
#include <glfw/glfw3.h>

class input
{
public:
	
	static void update(GLFWwindow* window);
	static bool isKeyDown(int key);
	static bool isKeyPressed(int key);
	static bool isKeyReleased(int key);
	static glm::vec2 getMousePos(void);
	static bool isLMBDown(void);
	static bool isLMBPressed(void);
	static bool isLMBReleased(void);
	static bool isRMBDown(void);
	static bool isRMBPressed(void);
	static bool isRMBReleased(void);

private:
	input(void);
	~input(void);

	static bool kbState[GLFW_KEY_LAST];
	static bool oldKbState[GLFW_KEY_LAST];
	static GLFWwindow* window;
	/*priv mouse state*/
};

