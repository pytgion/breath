#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

#include <iostream>

class Window
{
private:
	GLFWwindow* window;		

public:
	Window(int Heigth, int Width, const char* Title);
	~Window();

	void PollEvent();
	void SwapBuffers();

	GLFWwindow* GetWindow();
};

#endif
