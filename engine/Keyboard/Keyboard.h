#pragma once


#include <queue>
#include <vector>
#include "KeyboardEvent.h"


/*
	> Offer Keyboard Events [KeyDown, KeyUp] (no buffering)
	> Offer reading Text Streams (buffering)

	Current Implementation of ReadChar and ReadEvent is not meant for threading
		-> If one thread reads a char or an event
		-> that event is lost to all other threads
	
	TODO-------
	----> Implement an event dispatch system
	----> Consumer - subscription kind
*/


class Keyboard
{
public:
	Keyboard();

	bool IsKeyPressed(const unsigned char keyCode);
	bool IsEventQueueEmpty();
	bool IsCharQueueEmpty();

	KeyboardEvent ReadEvent();
	unsigned char ReadChar();

	void OnKeyPressed(const unsigned char keyCode);
	void OnKeyReleased(const unsigned char keyCode);
	void OnChar(const unsigned char keyCode);
	void OnLostFocus();

	void EnableAutoRepeatEvents();
	void EnableAutoRepeatChars();

	void DisableAutoRepeatEvents();
	void DisableAutoRepeatChars();

	bool IsEventOnAutoRepeat();
	bool IsCharsOnAutoRepeat();


private:

	bool autoRepeatEvents	= false;
	bool autoRepeatChars	= false;

	bool keyStates[256];

	std::queue<KeyboardEvent> eventQueue;
	std::queue<unsigned char> charQueue;

};

