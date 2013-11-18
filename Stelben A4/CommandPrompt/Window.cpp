/*--------------------------------------------------------------------------------------------------
This class was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#include "Window.h"

// Gets the Windows handle
HANDLE Window::hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );


void Window::initalize()
{
	SetConsoleTitle( "Command Prompt Title" );		// Sets the name of the console window

	// Set Screen Buffer
	COORD windowSize = { WINDOW_WIDTH + 1, WINDOW_HEIGHT + 1};
	SetConsoleScreenBufferSize( hConsole, windowSize );

	// Set Starting Height/Width of Console
	SMALL_RECT screenRect;
	screenRect.Left		= 0;
	screenRect.Top		= 0;
	screenRect.Right	= WINDOW_WIDTH + 1;
	screenRect.Bottom	= WINDOW_HEIGHT + 1;	

	SetConsoleWindowInfo( hConsole, true, &screenRect);
}

// Moves the Console Cursor to where you specify
void Window::setCursorPosition( const unsigned short x, const unsigned short y )
{
	COORD position = { x, y };
	SetConsoleCursorPosition( hConsole, position );
}

