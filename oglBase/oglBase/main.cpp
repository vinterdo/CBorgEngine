#include "application.h"
#include "testScene1.h"

int main( void )  
{  
	application* app = new application();
	app->setScene(new testScene1());
	app->run();
} 