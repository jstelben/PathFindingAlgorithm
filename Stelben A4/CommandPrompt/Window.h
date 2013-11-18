/*--------------------------------------------------------------------------------------------------
This class was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <stdio.h>
#include <iostream>

class Window
{
public:
	// Methods
	static void initalize();
	static void setCursorPosition( const unsigned short x, const unsigned short y );		// Moves the Console Cursor to where you specify

	// Width and Height of the Console
	static const unsigned __int16	WINDOW_WIDTH	= 80;
	static const unsigned __int16	WINDOW_HEIGHT	= 25;

private:
	// Attributes
	static HANDLE hConsole;
};

#endif

