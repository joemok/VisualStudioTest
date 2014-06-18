#include <GL/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include "Window.h"
#include "Mesh.h"


int main(int argc, char** argv)
{
	Window W(800, 600, "Window");


	while (!W.isClosed()){
		
		W.Clear(0.0f, 1.0f, 0.3f, 0.5f);

		W.swapBuffers();
	}

	std::cin.get();
	return 0;
}