#include "Window.h"

Window::Window(int Heigth, int Width, const char* Title)
{
	if(!glfwInit())
	{
		std::cerr << "Failed to initalize GLFW" << std::endl;
	}

	window = glfwCreateWindow(Heigth, Width, Title, nullptr, nullptr);
	if (!window)
	{
		std::cerr<< "Failed to create window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
}

Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::PollEvent()
{
	glfwPollEvents();
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(window);
}

GLFWwindow* Window::GetWindow()
{
	return window;
}
