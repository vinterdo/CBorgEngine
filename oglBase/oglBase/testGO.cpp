#include "testGO.h"
#include "shader_tmp.h"

testGO::testGO(void)
{
}


testGO::~testGO(void)
{
}

void testGO::start(void)
{
	sh = new shader();
	sh->load("SingleColor");
	m = new mesh();
	m->load("C:/cube.obj");
	getTrans()->setRotation(glm::quat(glm::vec3(1, 1, 1)));
	
	MatrixID = sh->getUniformId("MVP");
	glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f);
	glm::mat4 View       = glm::lookAt(
								glm::vec3(0,0,3), // Camera is at (4,3,3), in World Space
								glm::vec3(0,0,0), // and looks at the origin
								glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
						   );
	MVP        = Projection * View; 

	vertexPosition_modelspaceID = sh->getAttribId("vertexPosition_modelspace");

	/*static const GLfloat g_vertex_buffer_data[] = { 
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f
	};

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);*/

}

void testGO::draw(void)
{
	sh->start();
	sh->setValue("color", &color);
	sh->setValue("MVP", &(MVP * getTrans()->getModelMatrix()));
	//glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &(MVP * getTrans()->getModelMatrix())[0][0]);

	glEnableVertexAttribArray(vertexPosition_modelspaceID);
	glBindBuffer(GL_ARRAY_BUFFER, m->getVertexBufferId());
	glVertexAttribPointer(
		vertexPosition_modelspaceID, // The attribute we want to configure
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glDrawArrays(GL_TRIANGLES, 0, 6); 

	glDisableVertexAttribArray(vertexPosition_modelspaceID);
}

void testGO::destroy(void)
{
}
void testGO::fixedUpdate(void)
{
}
void testGO::update(void)
{
}