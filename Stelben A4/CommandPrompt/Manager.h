/*--------------------------------------------------------------------------------------------------
This class was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#ifndef MANAGER_H
#define MANAGER_H

#include "Window.h"
#include "Timer.h"
#include "KeyBoard.h"


class Manager
{

public:
		static void initalize();
		static void update();
		static void deinitalize();			// Run this when it is not needed
};

#endif

