#pragma once
#include "light.h"
class directionalLight :
	public light
{
public:
	directionalLight(glm::vec3 color, glm::vec3 direction, float power);
	~directionalLight(void);

	static void passDirectionalLights(int dirLocation, int colorLocation, int powerLocation);
	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);

private:
	glm::vec3 direction;
	static std::vector<directionalLight*> directionalLights;
};

