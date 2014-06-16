#include "Display.h"

Display::Display(int width, int height, const std::string& name)
{
	std::cout << "Constructor!" << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);
}


Display::~Display()
{
	std::cout << "Destructor!" << std::endl;
	SDL_Quit();
}
