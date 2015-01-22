#pragma once
#include "component.h"
#include <vector>
#include "terrain.h"
#include <string>
class lodManager :
	public component
{
public:
	lodManager(std::string path);
	~lodManager(void);

	std::vector<gameObject*> terrains;
	int current;
	bool automode;

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);
};

