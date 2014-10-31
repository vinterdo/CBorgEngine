#pragma once
#include "component.h"
class meshRenderer : public component
{
public:
	meshRenderer(void);
	~meshRenderer(void);

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);
};

