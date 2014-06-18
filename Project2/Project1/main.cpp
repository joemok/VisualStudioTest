#include <GL/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include "display.h"
#include "shader.h"
#include "mesh.h"


int main(int argc, char** argv)
{
	Display display(800, 600, "Window");

	Vertex verticies[] = {	Vertex(glm::vec3(-0.5f, -0.5f, 0.0f)),
							Vertex(glm::vec3(0.0f, 0.5f, 0.0f)),
							Vertex(glm::vec3(0.5f, -0.5f, 0.0f)) };

	Mesh mesh(verticies, sizeof(verticies) / sizeof(verticies[0]));
	Shader shader("./res/basicShader");

	while (!display.isClosed()){

		display.Clear(0.0f, 0.0f, 0.3f, 0.5f);
		shader.Bind();
		mesh.Draw();
		display.swapBuffers();
	}

	return 0;
}