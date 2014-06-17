#include <GL/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include "display.h"
#include "shader.h"


int main(int argc, char** argv)
{
	Display display(800, 600, "Window");

	Shader shader("./res/basicShader");
	while (!display.isClosed()){

		display.Clear(0.0f, 1.0f, 0.3f, 0.5f);
		shader.Bind();
		display.swapBuffers();
	}

	std::cin.get();
	return 0;
}