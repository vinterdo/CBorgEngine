#include <iostream>
#include "application.h"
#include "testScene1.h"
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
	meshRenderer* mr = new meshRenderer();
	mesh* m = new mesh();
	m->load("C:/cube.obj");
	material* mat = new material();
	mat->load("");
	mr->setMesh(m);
	mr->setMat(mat);
	go->addComponent(mr);
	testScene->addGO(go);

	app->run();
} 