#pragma once
#include <glm.hpp>
#include <vector>
#include "component.h"

class mesh : public component
{
public:
	mesh(void);
	~mesh(void);

	void beginDraw();
	void endDraw();

	virtual void draw(void);
	virtual void update(void);
	virtual void fixedUpdate(void);
	virtual void destroy(void);
	virtual void start(void);

	bool loadObjFile(const char * path);

private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
};

