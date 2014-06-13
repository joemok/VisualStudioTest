#include "Window.h"
#include <GL\glew.h>
#include <iostream>



Window::Window(int width, int height, const std::string& title)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); //How transparent
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	GLenum status = glewInit();

	if (status != GLEW_OK){

		std::cerr << "Glew failed" << std::endl;

	}

	m_isClosed = false;
}


Window::~Window()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_GL_DeleteContext(m_window);
	SDL_Quit();
}

bool Window::isClosed(){
	return m_isClosed;
}

void Window::swapBuffers(){

	SDL_GL_SwapWindow(m_window);

	SDL_Event e;

	while (SDL_PollEvent(&e)){

		if (e.type == SDL_QUIT){
			m_isClosed = true;
		}
	}
}
