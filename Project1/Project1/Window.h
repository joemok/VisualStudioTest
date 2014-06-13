#pragma once
#include <iostream>
#include <string>
#include <SDL\SDL.h>

class Window
{
public:
	Window(int width, int height, const std::string& title);
	~Window();
	
	void swapBuffers();
	bool isClosed();

private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

