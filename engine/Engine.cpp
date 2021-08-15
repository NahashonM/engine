#include "Engine.h"



bool Engine::Initialize(HINSTANCE hInstance, std::string winTitle, std::string winClass, int width, int height)
{
	return this->renderWindow.Initialize(this,hInstance, winTitle, winClass, width, height);
}

bool Engine::ProcessMessages()
{
	return this->renderWindow.ProcessMessages();
}


Engine::Engine()
{
}


Engine::~Engine()
{
}
