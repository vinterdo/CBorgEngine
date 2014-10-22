#pragma once
#include <vector>
#include "gameObject.h"
#include <glm.hpp>

class scene
{
public:
	scene(void);
	~scene(void);

	virtual void start();
	virtual void update();
	virtual void fixedUpdate();
	virtual void draw();
	virtual void destroy();

	void addGO(gameObject* GO);
	void removeGO(gameObject* GO);

private:
	std::vector<gameObject*> objects;
};

