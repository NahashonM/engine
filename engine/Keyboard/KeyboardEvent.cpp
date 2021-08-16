#include "KeyboardEvent.h"



KeyboardEvent::KeyboardEvent()
	:	type(Invalid), 
		key('\0')
{
}

KeyboardEvent::KeyboardEvent(const EventType type, const unsigned char key)
	:	type(type), 
		key(key)
{
}


bool KeyboardEvent::IsPress() const
{
	return type == EventType::KeyPress;
}

bool KeyboardEvent::IsRelease() const
{
	return type == EventType::KeyRelease;
}

bool KeyboardEvent::IsValid() const
{
	return type != EventType::Invalid;
}


unsigned char KeyboardEvent::GetKeyCode() const
{
	return key;
}
