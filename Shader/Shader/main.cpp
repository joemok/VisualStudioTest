#include <GL/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"

int main(int argc, char** argv)
{
	Display W(800, 600, "Window");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0.0)),
						  Vertex(glm::vec3(0.0, 0.5, 0)),
						  Vertex(glm::vec3(0.5, -0.5, 0)), };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/basicShader");

	while (!W.isClosed()){

		W.Clear(0.0f, 0.5f, 0.3f, 0.5f);
		shader.Bind();
		mesh.Draw();

		W.swapBuffers();
	}

	std::cin.get();
	return 0;
}