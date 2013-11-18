/*--------------------------------------------------------------------------------------------------
This class was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#include "KeyBoard.h"
#include <windows.h>

unsigned __int8 * KeyBoard::_keys = nullptr;	// initalize _keys to null

#pragma  region Initalzie
void KeyBoard::initalize()
{
	_keys = new unsigned __int8[BUFFER_SIZE];
}
#pragma endregion

#pragma region Update
void KeyBoard::update()
{
	if(_keys)
	{
		for(unsigned short index = 0; index < BUFFER_SIZE; ++index )
		{
			unsigned __int8 keyState = _keys[index];
			unsigned __int8 currentKeyState;

			// Check the current state of key
			// Key Down
			if( GetKeyState(index) & 0x800 )		// if high order bit is 1, then key is down
			{
				if( keyState == KEY_DOWN || keyState == KEY_PRESSED )
				{
					currentKeyState = KEY_DOWN;
				}
				else
				{
					currentKeyState = KEY_PRESSED;
				}
			}
			// Key Up
			else
			{
				if( keyState == KEY_UP || keyState == KEY_RELEASED )
				{
					currentKeyState = KEY_UP;
				}
				else
				{
					currentKeyState = KEY_RELEASED;
				}
			}

			_keys[index] = currentKeyState;
		}
	}
}
#pragma endregion

#pragma region Deinitalize
void KeyBoard::deinitalize()
{
	delete _keys;
}
#pragma endregion

#pragma region GetKeyState
unsigned __int8 KeyBoard::GetCurrentKeyState( const unsigned __int8 key )
{
	if( _keys )
	{
		return _keys[key];
	}

	return 0;
}
#pragma endregion