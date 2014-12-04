#include <iostream>
#include "application.h"
#include "testGO.h"
#include "meshRenderer.h"
#include "mesh.h"
#include "material.h"
#include "uniformValue.h"
#include "camera.h"
#include "simple2DCamMove.h"
#include "tex2d.h"

int main( void )  
{  
	application* app = new application();
	app->start();
	scene* testScene = new scene();
	app->setScene(testScene);

	gameObject* go = new gameObject();
	go->getTrans()->setRotation(glm::quat(glm::vec3(1, 1, 1)));
	go->getTrans()->setScale(glm::vec3(0.1, 0.1, 0.1));
	meshRenderer* mr = new meshRenderer();
	mesh* m = mesh::loadNew("spider.obj");
	material* mat = new material();
	shader* sh = shader::loadNew("Diffuse");
	tex2d* tex = new tex2d();
	tex->load("rock_tex.jpg");
	sh->setValue("mainTex", new uniformTex2d(tex));
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
	cam->setProjectionPerspective(45, 4,3, 0.1, 50);
	simple2DCamMove* move = new simple2DCamMove();
	camGo->addComponent(move);
	testScene->addGO(camGo);

	app->run();
} 