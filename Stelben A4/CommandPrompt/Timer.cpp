/*--------------------------------------------------------------------------------------------------
This class was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#include "Timer.h"

unsigned short Timer::_previousTime	= 0;
unsigned short Timer::_currentTime	= 0;
unsigned short Timer::_deltaTime	= 0;


void Timer::initalize()
{
	_previousTime	= static_cast<short>(timeGetTime());
	_currentTime	= static_cast<short>(_previousTime);
	_deltaTime		= 0;

}

void Timer::update()
{
	_previousTime	= static_cast<short>(_currentTime);
	_currentTime	= static_cast<short>(timeGetTime());
	_deltaTime		= _currentTime - _previousTime;
}