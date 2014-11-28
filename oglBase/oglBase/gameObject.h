#pragma once

#include <GL/glew.h>  
#include <GLFW/glfw3.h>  
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>
#include <sstream>
#include <vector>
#include "transform.h"
#include "component.h"
#include <string>

class gameObject
{
public:
	gameObject(void);
	~gameObject(void);

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);

	void addComponent(component* c);
	//void removeComponent();
	
	transform* getTrans(void);
	void setTrans(transform t);
	bool disabled;

	template<typename T>
	T getComponent()
	{
		//printf("%s type of T : ", typeid(T).name());
		for(int i=0; i < components.size(); i++)
		{
			//printf("%s type of T : ", typeid(components[i]).name());
			if(dynamic_cast<T>(components[i]) != NULL)
			{
				return (T)components[i];
			}
		}
		return NULL;
	}

	int getComponentCount();
	void setPosition(glm::vec3);

private:
	transform trans;
	std::vector<component*> components;
};

