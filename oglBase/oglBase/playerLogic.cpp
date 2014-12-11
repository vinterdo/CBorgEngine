#include "playerLogic.h"

int playerLogic::points = 0;

playerLogic::playerLogic(gameObject* _tpCam, gameObject* _sideCam)
{
	tpCam = _tpCam;
	sideCam = _sideCam;
}


playerLogic::~playerLogic(void)
{
}
