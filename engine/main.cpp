

#include "engine.h"



int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine, 
	_In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);

	Engine engine;
	engine.Initialize(hInstance, "NoobEngine", "NoobEngineClass", 800, 600);

	while (engine.ProcessMessages()) {

		engine.Update();
		
		Sleep(10);
	}

	return 0;
}
