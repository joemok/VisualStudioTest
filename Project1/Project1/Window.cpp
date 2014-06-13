#include "Window.h"
#include <iostream>


Window::Window(int width, int height, const std::string& title)
{
	std::cout << "Constructor" << std::endl;
}


Window::~Window()
{
	std::cout << "Destructor" << std::endl;
}
