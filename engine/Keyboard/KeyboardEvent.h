#pragma once


class KeyboardEvent
{
public:

	enum EventType {
		KeyPress,
		KeyRelease, 
		Invalid
	};


	///<summary>Generate Invalid Event</summary>
	KeyboardEvent();

	///<summary>Generate Valid Event</summary>
	KeyboardEvent(const EventType type, const unsigned char key);

	bool IsPress() const;
	bool IsRelease() const;
	bool IsValid() const;

	///<summary> Returns the key code </summary>
	unsigned char GetKeyCode() const;

private:
	EventType		type;
	unsigned char	key;
};

