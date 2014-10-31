#include "application.h"
#include "testScene1.h"

int main( void )  
{  
	application* app = new application();
	scene* testScene = new testScene1();
	app->setScene(testScene);
	app->run();
} 