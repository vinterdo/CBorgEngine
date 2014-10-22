#include "testScene1.h"
#include "input.h"
#include <vector>
#include <algorithm>

testScene1::testScene1()
{
	flipCount = 0;
	countdown = 0;
}


testScene1::~testScene1(void)
{
}

void testScene1::start(void)
{
	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1, 0 ,1));
	colors.push_back(glm::vec3(1, 1 ,0));
	colors.push_back(glm::vec3(1, 0 ,0));
	colors.push_back(glm::vec3(1, 1 ,1));
	colors.push_back(glm::vec3(0, 0 ,1));
	colors.push_back(glm::vec3(0, 1 ,0));
	colors.push_back(glm::vec3(0.2, 0.2 ,0.2));
	colors.push_back(glm::vec3(0, 1 ,1));
	colors.push_back(glm::vec3(1, 0 ,1));
	colors.push_back(glm::vec3(1, 1 ,0));
	colors.push_back(glm::vec3(1, 0 ,0));
	colors.push_back(glm::vec3(1, 1 ,1));
	colors.push_back(glm::vec3(0, 0 ,1));
	colors.push_back(glm::vec3(0, 1 ,0));
	colors.push_back(glm::vec3(0.2, 0.2 ,0.2));
	colors.push_back(glm::vec3(0, 1 ,1));
	
	
	srand(time(NULL));
	std::random_shuffle (colors.begin(), colors.end());

	for(int i =0; i < 16; i++)
	{
		testGO* go = new testGO();
		transform t;
		t.setPos(glm::vec3((i % 4) * 3 - 4.5, (i - i%4)/4 * 3 - 4.5, 0));
		go->setTrans(t);
		go->color = colors[i];
		cards.push_back(go);
		addGO(go);
	}

	selectedID = 0;
	cards[0]->selected = true;
}

void testScene1::update(void)
{
	if(input::isKeyDown(GLFW_KEY_UP))
	{
		cards[selectedID]->selected = false;
		selectedID = (selectedID + 4 + 16) % 16;
		cards[selectedID]->selected = true;
	}
	if(input::isKeyDown(GLFW_KEY_DOWN))
	{
		cards[selectedID]->selected = false;
		selectedID = (selectedID - 4 + 16) % 16;
		cards[selectedID]->selected = true;
	}
	if(input::isKeyDown(GLFW_KEY_RIGHT))
	{
		cards[selectedID]->selected = false;
		selectedID = (selectedID + 1 + 16) % 16;
		cards[selectedID]->selected = true;
	}
	if(input::isKeyDown(GLFW_KEY_LEFT))
	{
		cards[selectedID]->selected = false;
		selectedID = (selectedID - 1 + 16) % 16;
		cards[selectedID]->selected = true;
	}
	if(input::isKeyDown(GLFW_KEY_ENTER) && !cards[selectedID]->flipped && !cards[selectedID]->disabled && countdown == 0)
	{
		cards[selectedID]->flipped = true;
		flipCount++;
	}

	scene::update();
}

bool vec3Comparison(const glm::vec3 &vecA, const glm::vec3 &vecB)
{
	return vecA[0]==vecB[0] 
        && vecA[1]==vecB[1] 
        && vecA[2]==vecB[2];
}

void testScene1::fixedUpdate()
{
	if(countdown > 0)
	{
		if(countdown == 1)
		{
			int id = -1;
			for(int i=0; i < 16; i++)
			{
				if(id != -1 && cards[i]->flipped) 
				{
					if(vec3Comparison(cards[i]->color,cards[id]->color))
					{
						cards[i]->disabled = true;
						cards[id]->disabled = true;
					}
				}
				
				if(id == -1 && cards[i]->flipped) id = i;
				cards[i]->flipped = false;
			}
		}
		countdown--;
	}
	if(flipCount >= 2)
	{
		flipCount = 0;
		countdown = 180;
	}
}
