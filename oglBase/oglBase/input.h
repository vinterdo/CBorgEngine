#pragma once
#include <glm.hpp>
class input
{
public:
	input(void);
	~input(void);

	void update(void);
	bool isKeyDown(/*key*/);
	bool isKeyPressed(/*key*/);
	bool isKeyReleased(/*key*/);
	glm::vec2 getMousePos(void);
	bool isLMBDown(void);
	bool isLMBPressed(void);
	bool isLMBReleased(void);
	bool isRMBDown(void);
	bool isRMBPressed(void);
	bool isRMBReleased(void);

private:
	/*priv kb state*/
	/*priv mouse state*/
};

