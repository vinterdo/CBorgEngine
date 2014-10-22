#pragma once
#include "scene.h"
#include "testGO.h"

class testScene1 : public scene 
{
public:
	testScene1(void);
	~testScene1(void);

	virtual void start(void);
	virtual void update(void);
private:
	std::vector<testGO*> cards;
};

