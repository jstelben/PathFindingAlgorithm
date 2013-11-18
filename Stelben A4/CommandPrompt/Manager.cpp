/*--------------------------------------------------------------------------------------------------
This class was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#include "Manager.h"


void Manager::initalize()
{
	Window::initalize();
	Timer::initalize();
	KeyBoard::initalize();
}

void Manager::update()
{
	Timer::update();
	KeyBoard::update();
}

void Manager::deinitalize()
{
	KeyBoard::deinitalize();
}