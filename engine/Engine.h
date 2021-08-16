#pragma once

#include "WindowContainer.h"


class Engine : WindowContainer
{
public:
	bool Initialize(HINSTANCE hInstance, std::string winTitle, std::string winClass, int width, int height);

	bool ProcessMessages();

	void Update();

	Engine();
	~Engine();
};

