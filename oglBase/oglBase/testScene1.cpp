#include "testScene1.h"


testScene1::testScene1(void)
{
}


testScene1::~testScene1(void)
{
}

void testScene1::start(void)
{
	for(int i =0; i < 16; i++)
	{
		testGO* go = new testGO();
		transform t;
		t.setPos(glm::vec3((i % 4) * 3 - 4.5, (i - i%4)/4 * 3 - 4.5, 0));
		go->setTrans(t);
		addGO(go);
	}
}

