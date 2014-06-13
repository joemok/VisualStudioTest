#include <GL/glew.h>
#include <iostream>
#include "Window.h"

int main(int argc, char** argv)
{
	Window W(800, 600, "Hello World");

	while (!W.isClosed()){
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		W.swapBuffers();
	}

	std::cin.get();
	return 0;
}