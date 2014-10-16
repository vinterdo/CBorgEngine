#pragma once
#include <vector>
#include "gameObject.h"

class scene
{
public:
	scene(void);
	~scene(void);

	void start();
	void update();
	void fixedUpdate();
	void draw();
	void destroy();

	void addGO(gameObject GO);
	void removeGO(gameObject GO);

private:
	std::vector<gameObject> objects;
};

