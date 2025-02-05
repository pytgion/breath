#include "Runtime.h"

Runtime::Runtime()
{
	window = new Window(1600, 900, "Breath");
	bIsRunning = true;
}

Runtime::~Runtime()
{
	delete window;
}

void Runtime::Run()
{
	while(bIsRunning)
	{
		if(glfwGetKey(window->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
    		{
		    bIsRunning = false;
    		}
		window->PollEvent();
		window->SwapBuffers();
	}
}
