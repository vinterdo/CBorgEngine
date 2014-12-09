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
#include "pointLight.h"
#include "BubbleGenerator.h"

void GenerateBoxes(scene* testScene, glm::vec3 pos, glm::vec3 scale)
{
	material* mat = new material();
	shader* sh = shader::loadNew("BlinnPhong");
	tex2d* tex = new tex2d();
	tex->load("rock_tex.jpg");
	sh->setValue("mainTex", new uniformTex2d(tex));
	mat->setShader(sh);
	gameObject* backPlane = new gameObject();
	backPlane->getTrans()->setPos(pos);
	backPlane->getTrans()->setScale(scale);
	meshRenderer* mr = new meshRenderer();
	mesh* m = mesh::loadNew("cube.obj");
	mr->setMesh(m);
	mr->setMat(mat);
	backPlane->addComponent(mr);
	testScene->addGO(backPlane);
}

int main( void )  
{  
	application* app = new application();
	app->start();
	scene* testScene = new scene();
	app->setScene(testScene);

	GenerateBoxes(testScene, glm::vec3(0,0,-10), glm::vec3(20,10,1));
	GenerateBoxes(testScene, glm::vec3(0,10,0), glm::vec3(20,1,10));
	GenerateBoxes(testScene, glm::vec3(0,-10,0), glm::vec3(20,1,10));
	GenerateBoxes(testScene, glm::vec3(-20,0,0), glm::vec3(1,10,10));
	GenerateBoxes(testScene, glm::vec3(20,0,0), glm::vec3(1,10,10));

	gameObject* bubbleGen = new gameObject();
	bubbleGen->addComponent(new bubbleGenerator());
	testScene->addGO(bubbleGen);

	gameObject* player = new gameObject();
	material* mat = new material();
	shader* sh = shader::loadNew("BlinnPhong");
	tex2d* tex = new tex2d();
	tex->load("rock_tex.jpg");
	sh->setValue("mainTex", new uniformTex2d(tex));
	mat->setShader(sh);
	meshRenderer* mr = new meshRenderer();
	mesh* m = mesh::loadNew("chark.3ds", 2);
	mr->setMesh(m);
	mr->setMat(mat);
	player->addComponent(mr);
	player->getTrans()->setRotation(glm::quat(glm::vec3(0.0,1.57,1.57)));
	player->getTrans()->setScale(glm::vec3(0.005,0.005,0.005));
	testScene->addGO(player);


	gameObject* camGo = new gameObject();
	camGo->getTrans()->setPos(glm::vec3(0,0,35));
	camera* cam = new camera();
	camGo->addComponent(cam);
	//simple2DCamMove* move = new simple2DCamMove();
	//camGo->addComponent(move);
	cam->setProjectionPerspective(45, 4,3, 0.1, 500);

	pointLight* plight = new pointLight(glm::vec3(0.5,0.5,0.5), 50);
	camGo->addComponent(plight);

	testScene->addGO(camGo);

	app->run();
} 