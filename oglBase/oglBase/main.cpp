#include "application.h"
#include "testScene1.h"

int main( void )  
{  
	application* app = new application();
	scene* testScene = new scene();
	app->setScene(testScene);
	app->run();
} 