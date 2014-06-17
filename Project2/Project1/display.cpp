#include "display.h"
#include <iostream>


Display::Display(int width, int height, const std::string& title)
{
	std::cout << "Display Constructor" << std::endl;
}


Display::~Display()
{
	std::cout << "Display Destructor" << std::endl;
}
