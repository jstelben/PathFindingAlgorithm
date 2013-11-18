/*--------------------------------------------------------------------------------------------------
This class was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#ifndef TIMER_H
#define TIMER_H

#include <windows.h>				// Needed for timer
#pragma comment(lib, "winmm.lib")	// Used to get time in Milliseconds

class Timer
{

public:

	// Methods
	static void initalize();
	static void update();

	// Attributes
	static const unsigned short		SECOND = 500;			// 500 = 1sec

	// Properties
	static unsigned short DeltaTime(){ return _deltaTime; }

private:
	// Attributes
	static unsigned short	_currentTime;
	static unsigned short	_previousTime;
	static unsigned short	_deltaTime;

};

#endif

