#include "Keyboard.h"



Keyboard::Keyboard()
{
	this->OnLostFocus();
}



bool Keyboard::IsKeyPressed(const unsigned char keyCode)
{
	return keyStates[keyCode];
}



bool Keyboard::IsEventQueueEmpty()
{
	return this->eventQueue.empty();
}

bool Keyboard::IsCharQueueEmpty()
{
	return this->charQueue.empty();
}



KeyboardEvent Keyboard::ReadEvent()
{
	if (!this->eventQueue.empty()) {
		KeyboardEvent tmp = this->eventQueue.front();
		this->eventQueue.pop();
		return tmp;
	}

	return KeyboardEvent();
}

unsigned char Keyboard::ReadChar()
{
	if (!this->charQueue.empty()) {
		unsigned char tmp = this->charQueue.front();
		this->charQueue.pop();
		return tmp;
	}

	return 0u;
}



void Keyboard::OnKeyPressed(const unsigned char keyCode)
{
	keyStates[keyCode] = true;
	this->eventQueue.push(KeyboardEvent(KeyboardEvent::EventType::KeyPress, keyCode));
}

void Keyboard::OnKeyReleased(const unsigned char keyCode)
{
	keyStates[keyCode] = false;
	this->eventQueue.push(KeyboardEvent(KeyboardEvent::EventType::KeyRelease, keyCode));
}

void Keyboard::OnChar(const unsigned char keyCode)
{
	this->charQueue.push(keyCode);
}

void Keyboard::OnLostFocus()
{
	memset(keyStates, false, sizeof(keyStates));
}






void Keyboard::EnableAutoRepeatEvents()
{
	this->autoRepeatEvents = true;
}

void Keyboard::EnableAutoRepeatChars()
{
	this->autoRepeatChars = true;
}

void Keyboard::DisableAutoRepeatEvents()
{
	this->autoRepeatEvents = false;
}

void Keyboard::DisableAutoRepeatChars()
{
	this->autoRepeatChars = false;
}

bool Keyboard::IsEventOnAutoRepeat()
{
	return this->autoRepeatEvents;
}

bool Keyboard::IsCharsOnAutoRepeat()
{
	return this->autoRepeatChars;
}
