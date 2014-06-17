#pragma once
#include <string>
#include <SDL\SDL.h>


class Display
{
public:
	Display(int width, int height, const std::string &title);
	void Update();
	bool IsClosed(){ return m_isClosed; }
	~Display();

private:

	Display(const Display& other){}
	Display operator=(const Display& other){}
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

