/*--------------------------------------------------------------------------------------------------
This class was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#ifndef KEYBOARD_H
#define KEYBOARD_H

enum KeyState { KEY_UP, KEY_RELEASED, KEY_DOWN, KEY_PRESSED };

class KeyBoard
{

public:
	static void initalize();
	static void update();
	static void deinitalize();

	static unsigned __int8 GetCurrentKeyState( const unsigned __int8 key );		// Gets the state of the requested key

private:
	static unsigned __int8 * _keys;						// Array of Keys

	static const unsigned __int8 BUFFER_SIZE = 255;		// Size of the Array of keys
};

#endif

