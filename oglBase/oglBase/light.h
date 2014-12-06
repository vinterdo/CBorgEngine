#pragma once
#include "component.h"


// light types: spot, directional, point, area

class light :
	public component
{
public:
	light(void);
	~light(void);
};

