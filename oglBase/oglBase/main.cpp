#include <iostream>
#include "application.h"
#include "testGO.h"
#include "meshRenderer.h"
#include "mesh.h"
#include "material.h"

int main( void )  
{  
	application* app = new application();
	app->start();
	scene* testScene = new scene();
	
	app->setScene(testScene);

	gameObject* go = new gameObject();
	go->setPosition(glm::vec3(0,0, -10));
	meshRenderer* mr = new meshRenderer();
	mesh* m = new mesh();
	m->load("C:/cube.obj");
	material* mat = new material();
	shader* sh = new shader();
	sh->load("SingleColor");
	mat->setShader(sh);
	mr->setMesh(m);
	mr->setMat(mat);
	go->addComponent(mr);
	testScene->addGO(go);

	gameObject* test = new testGO();
	test->setPosition(glm::vec3(5,0,0));
	testScene->addGO(test);

	app->run();
} 