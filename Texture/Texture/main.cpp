#include <GL/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
 
int main(int argc, char** argv)
{
	Display W(800, 600, "Window");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0)),
						  Vertex(glm::vec3(0.0, 0.5, 0.0), glm::vec2(0.5, 1.0)),
						  Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1.0, 0.0)), };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");

	while (!W.isClosed()){

		W.Clear(0.0f, 0.3f, 0.7f, 1.0f);

		shader.Bind();
		texture.Bind(0);
		mesh.Draw();

		W.swapBuffers();
	}

	std::cin.get();
	return 0;
}