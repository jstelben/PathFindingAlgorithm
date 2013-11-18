/*--------------------------------------------------------------------------------------------------
This class was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/

#pragma once
#include "Manager.h"
#include "Grid.h"
#include "Vertex.cpp"
#include <iostream>

unsigned __int16 charPositionX = 0;								// Position of ASCII Character
unsigned __int16 charPositionY = 0;

const unsigned __int8 CHARACTER = 2;							// ASCII Characters of Character and Trail
const unsigned __int8 TRAIL = 1;

unsigned __int16 TIME_PER_MOVE = Timer::SECOND / 10;			// Amount of Time before another input is considered
unsigned __int16 timePassed;

enum Movement { Idle, UP, RIGHT, DOWN, LEFT };

unsigned __int8 GetMovement();									// Gets the current movement by reading the keyboard manager
void Move( unsigned __int8 movement );							// Moves the character around the screen

#pragma region Main
int main()
{
	Manager::initalize();

/*---------------------------------------------------------------------------
John Stelben
Jon Runkel
10/13/2013
Our part of the Main class
----------------------------------------------------------------------------*/

	//Make grid and initialize it.
	Grid g = Grid();
	g.Initialize();
	charPositionX = g.Player->X;
	charPositionY = g.Player->Y;

	//Draw walls and goal on screen
	Window::setCursorPosition( 7, 4 );
	std::cout<<"H";
	Window::setCursorPosition( 7, 5 );
	std::cout<<"H";
	Window::setCursorPosition( 7, 6 );
	std::cout<<"H";
	Window::setCursorPosition( 9, 5 );
	std::cout<<"O";

	// Print Character on the Screen
	Window::setCursorPosition( charPositionX, charPositionY );
	std::cout << CHARACTER;

	// Game Loop
	while(KeyBoard::GetCurrentKeyState('q') != KEY_PRESSED && KeyBoard::GetCurrentKeyState('Q') != KEY_PRESSED)
	{
		Manager::update();
		timePassed += Timer::DeltaTime();

		//When r is pressed, prints the path from the play to the goal at the bottom of the screen
		if(KeyBoard::GetCurrentKeyState('r') == KEY_PRESSED || KeyBoard::GetCurrentKeyState('R') == KEY_PRESSED)
		{
			Window::setCursorPosition(0, 20);
			g.Player = g.Map[charPositionX][charPositionY];
			g.FindPath();
			Window::setCursorPosition( charPositionX, charPositionY );
			g.Initialize();
		}


		if( TIME_PER_MOVE <= timePassed )
		{
			timePassed = TIME_PER_MOVE;

			unsigned __int8 movement = GetMovement();

			// Move
			if( movement != Idle )
			{
				timePassed = 0;
				Move( movement );
			}			
		}
	}



	
}
#pragma endregion

#pragma region GET Movement
unsigned __int8 GetMovement()
{
	unsigned __int8 movement = Idle;

	if( KeyBoard::GetCurrentKeyState('w') == KEY_DOWN || KeyBoard::GetCurrentKeyState('W') == KEY_DOWN)
	{
		movement = UP;
	}
	else if( KeyBoard::GetCurrentKeyState('d') == KEY_DOWN || KeyBoard::GetCurrentKeyState('D') == KEY_DOWN)
	{
		movement = RIGHT;
	}
	else if( KeyBoard::GetCurrentKeyState('s') == KEY_DOWN || KeyBoard::GetCurrentKeyState('S') == KEY_DOWN)
	{
		movement = DOWN;
	}
	else if( KeyBoard::GetCurrentKeyState('a') == KEY_DOWN || KeyBoard::GetCurrentKeyState('A') == KEY_DOWN)
	{
		movement = LEFT;
	}

	return movement;
}
#pragma endregion

#pragma region Move
void Move( unsigned __int8 movement )
{
	// Draw a trail
	Window::setCursorPosition( charPositionX, charPositionY );
	std::cout << TRAIL;

	switch( movement )
	{
		case UP: 
		{
			if( charPositionY > 0)
			{
				--charPositionY;
			}
		} break;

		case RIGHT: 
		{
			if( charPositionX < Window::WINDOW_WIDTH - 1)
			{
				++charPositionX;
			}
		} break;

		case DOWN: 
		{
			if( charPositionY < Window::WINDOW_HEIGHT - 1)
			{
				++charPositionY;
			}
		} break;

		case LEFT: 
		{
			if( charPositionX > 0)
			{
				--charPositionX;
			}
		} break;
	}

	// Draw Character in new position
	Window::setCursorPosition( charPositionX, charPositionY );
	std::cout << CHARACTER;
}
#pragma endregion