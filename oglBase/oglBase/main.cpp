#include <iostream>
#include "application.h"
#include "testScene1.h"
#include "mesh.h"

int main( void )  
{  
	application* app = new application();
	scene* testScene = new testScene1();
	gameObject* go = new gameObject();
	go->addComponent(new mesh());


	mesh* m= go->getComponent<mesh*>();
	printf("%s",  typeid(m).name());

	app->setScene(testScene);
	app->run();
} 