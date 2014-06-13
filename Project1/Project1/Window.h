#pragma once
#include <iostream>
#include <string>
#include <SDL\SDL.h>

class Window
{
public:
	Window(int width, int height, const std::string& title);
	~Window();
	
	void Clear(float r, float g, float b, float a);
	void swapBuffers();
	bool isClosed();

private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

