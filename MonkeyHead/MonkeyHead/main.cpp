#include <GL/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"

static const int DISPLAY_WIDTH = 800;
static const int DISPLAY_HEIGHT = 600;

int main(int argc, char** argv)
{
	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL");
	Shader shader("./res/basicShader");

	Vertex vertices[] = {   Vertex(glm::vec3(-0.5, -0.5, -1), glm::vec2(0.0, 0.0)),
							Vertex(glm::vec3(0, 0.5, -1), glm::vec2(0.5, 1.0)),
							Vertex(glm::vec3(0.5, -0.5, -1), glm::vec2(1.0, 0.0)),
						};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Texture texture("./res/bricks.jpg");
	while (!display.isClosed()){

		display.Clear(0.8f, 0.4f, 0.4f, 0.8f);
		shader.Bind();
		texture.Bind(0);
		mesh.Draw();

		display.swapBuffers();
	}

	return 0;
}