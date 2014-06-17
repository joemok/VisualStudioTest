#pragma once
#include <SDL\SDL.h>
#include <string>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();
	void Update();
	bool IsClosed(){ return m_isClosed; }

private:

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

