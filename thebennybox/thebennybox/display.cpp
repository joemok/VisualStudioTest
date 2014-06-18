#include <GL/glew.h>
#include "display.h"
#include <iostream>


Display::Display(int width, int height, const std::string& title)
{
	//std::cout << "constructor" << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);//can set addtional parameters that in not part of the SDL window
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);// HOW MUCH DATA IN BITS THAT SDL WILL ALLOCATE IN SIMGLE PIXEL
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);// switch between window and Opengl
	 
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		std::cerr << "Glew failed to initialize!" << std::endl;
	}
}


Display::~Display()
{
	std::cout << "destructor" << std::endl;
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

bool Display::IsClosed()
{
	return m_isClosed;
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r ,g, b,a);
	glClear(GL_COLOR_BUFFER_BIT);

}
//void Display::SwapBuffers()
void Display::Update()
{
	SDL_GL_SwapWindow(m_window);
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			m_isClosed = true;
	}


}