#include <iostream>
#include "application.h"
#include "testGO.h"
#include "meshRenderer.h"
#include "mesh.h"
#include "material.h"
#include "uniformValue.h"
#include "camera.h"
#include "simple2DCamMove.h"

int main( void )  
{  
	application* app = new application();
	app->start();
	scene* testScene = new scene();
	app->setScene(testScene);

	gameObject* go = new gameObject();
	go->getTrans()->setRotation(glm::quat(glm::vec3(1, 1, 1)));
	go->getTrans()->setScale(glm::vec3(2, 1, 4));
	meshRenderer* mr = new meshRenderer();
	mesh* m = mesh::loadNew("cube.obj");
	material* mat = new material();
	shader* sh = shader::loadNew("SingleColor");
	sh->setValue("color", new uniformVector3(glm::vec3(1,1,1)));
	mat->setShader(sh);
	mr->setMesh(m);
	mr->setMat(mat);
	go->addComponent(mr);
	testScene->addGO(go);

	gameObject* camGo = new gameObject();
	camGo->getTrans()->setPos(glm::vec3(0,0,9));
	camera* cam = new camera();
	camGo->addComponent(cam);
	//cam->setProjectionOrtho(-10, 10, -10, 10);
	cam->setProjectionPerspective(60, 100,90, 0, 1000);
	simple2DCamMove* move = new simple2DCamMove();
	camGo->addComponent(move);
	cam->setViewLookAt(glm::vec3(0,0,0), glm::vec3(0,1,0)); 
	testScene->addGO(camGo);

	app->run();
} 