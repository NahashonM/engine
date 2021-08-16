#include "Engine.h"



bool Engine::Initialize(HINSTANCE hInstance, std::string winTitle, std::string winClass, int width, int height)
{
	return this->renderWindow.Initialize(this,hInstance, winTitle, winClass, width, height);
}

bool Engine::ProcessMessages()
{
	return this->renderWindow.ProcessMessages();
}

void Engine::Update()
{
	while (!keyboard.IsCharQueueEmpty()) {
		char a = keyboard.ReadChar();
		std::string t = "";
		t += a;
		OutputDebugStringA(t.c_str());
	}

	while (!keyboard.IsEventQueueEmpty()) {
		KeyboardEvent a = keyboard.ReadEvent();
		if(a.IsPress())
			OutputDebugStringA("_");
		else if (a.IsRelease())
			OutputDebugStringA("|");
		else
			OutputDebugStringA("I");
	}
}


Engine::Engine()
{
}


Engine::~Engine()
{
}
