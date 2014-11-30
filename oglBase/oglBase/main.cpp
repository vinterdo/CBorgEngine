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
	go->getTrans()->setRotation(glm::quat(glm::vec3(1, 1, 1)));
	go->getTrans()->setScale(glm::vec3(2, 1, 4));
	meshRenderer* mr = new meshRenderer();
	mesh* m = mesh::loadNew("cube.obj");
	material* mat = new material();
	shader* sh = shader::loadNew("SingleColor");
	mat->setShader(sh);
	mr->setMesh(m);
	mr->setMat(mat);
	go->addComponent(mr);
	testScene->addGO(go);

	app->run();
} 