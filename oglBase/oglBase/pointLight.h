#pragma once
#include "light.h"

class pointLight :
	public light
{
public:
	pointLight(glm::vec3 color, float power);
	~pointLight(void);

	static void passPointLights(int posLocation, int colorLocation, int powerLocation);
	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);

private:
	static std::vector<pointLight*> pointLights;

};

