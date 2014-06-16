#pragma once
#include <iostream>
#include <string>
#include <SDL2\SDL.h>

class Display
{
public:
	Display(int width, int height, const std::string& name);
	~Display();
private:
	SDL_Window* m_window;
};

