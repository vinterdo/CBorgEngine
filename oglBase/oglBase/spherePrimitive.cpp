#include "spherePrimitive.h"
#include <cmath>
#define M_PI 3.141592653
#define M_PI_2 3.141592653/2

spherePrimitive::spherePrimitive(float radius, int rings, int sectors)
{
	float const R = 1./(float)(rings-1);
	float const S = 1./(float)(sectors-1);
	int r, s;

	vertices.resize(rings * sectors);
	normals.resize(rings * sectors);
	uvs.resize(rings * sectors);
	std::vector<glm::vec3>::iterator v = vertices.begin();
	std::vector<glm::vec3>::iterator n = normals.begin();
	std::vector<glm::vec2>::iterator t = uvs.begin();
	for(r = 0; r < rings; r++) 
	{
		for(s = 0; s < sectors; s++) 
		{
			float const y = sin( -M_PI_2 + M_PI * r * R );
			float const x = cos(2*M_PI * s * S) * sin( M_PI * r * R );
			float const z = sin(2*M_PI * s * S) * sin( M_PI * r * R );

			*t++ = glm::vec2(s*S, r*R);
			*v++ = glm::vec3(x,y,z) * radius;
			*n++ = glm::vec3(x,y,z);
		}
	}

	indices.resize(rings * sectors * 4);
	std::vector<unsigned int>::iterator i = indices.begin();
	for(r = 0; r < rings-1; r++) 
	{
		for(s = 0; s < sectors-1; s++) 
		{
			*i++ = (r+1) * sectors + s;
			*i++ = (r+1) * sectors + (s+1);
			*i++ = r * sectors + (s+1);
			*i++ = r * sectors + s;
			
		}
	}

	mode = GL_LINE_STRIP;

	build();
}


spherePrimitive::~spherePrimitive(void)
{
}

bool spherePrimitive::load(std::string path)
{
	return false;
}
