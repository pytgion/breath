#pragma once

#include "Window.h"

class Runtime
{
public:
	Runtime();
	~Runtime();

	void Run();
private:
	bool bIsRunning;
	Window* window;
};
