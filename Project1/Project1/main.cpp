#include <GL/glew.h>
#include <iostream>
#include "Window.h"

int main(int argc, char** argv)
{
	Window W(800, 600, "Window");

	while (!W.isClosed()){
		
		W.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		W.swapBuffers();
	}

	std::cin.get();
	return 0;
}