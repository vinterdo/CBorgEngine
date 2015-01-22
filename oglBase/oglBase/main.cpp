
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
#include "playerLogic.h"
#include "terrain.h"
#include "terrainSpherical.h"
#include "spherePrimitive.h"
#include "orbitCamera.h"
#include "lodManager.h"


int main(int argc, char *argv[])  
{  

	bool mode = false;
	std::string path = "N50E016.hgt";

	application* app = new application();
	settings set = settings();
	set.resX = 1280;
	set.resY = 720;
	app->setSettings(set);
	app->start();
	scene* testScene = new scene();
	app->setScene(testScene);

	if(mode)
	{
		gameObject* playerCamGO = new gameObject();
		camera* playerCam = new camera();
		playerCam->setProjectionPerspective(45, 4,3, 0.1, 1000);
		playerCamGO->addComponent(playerCam);
		playerCamGO->getTrans()->setRotation(glm::quat(glm::vec3(-0.7,0,0.0)));
		playerCamGO->getTrans()->setPos(glm::vec3(256,450,700));
		orbitCamera* ocam = new orbitCamera(glm::vec3(0,0,0), 300);
		ocam->rotateSpeed = 0.001f;
		playerCamGO->addComponent(ocam);
		testScene->addGO(playerCamGO);

		gameObject* terrainGO = new gameObject();

		terrainSpherical* tr = new terrainSpherical(100);
		tr->load(path);

		terrainGO->addComponent(tr);
		testScene->addGO(terrainGO);
	}
	else
	{
		gameObject* playerCamGO = new gameObject();
		camera* playerCam = new camera();
		playerCam->setProjectionPerspective(45, 4,3, 0.1, 1000);
		playerCamGO->addComponent(playerCam);
		playerCamGO->getTrans()->setRotation(glm::quat(glm::vec3(-0.7,0,0.0)));
		playerCamGO->getTrans()->setPos(glm::vec3(256,450,700));
		simple2DCamMove* ocam = new simple2DCamMove();
		playerCamGO->addComponent(ocam);
		testScene->addGO(playerCamGO);

		gameObject* terrainGO = new gameObject();

		//terrain* tr = new terrain();
		//tr->load("N50E016.hgt");
		lodManager* tr = new lodManager(path);

		terrainGO->addComponent(tr);
		testScene->addGO(terrainGO);
	}

	app->run();
} 
