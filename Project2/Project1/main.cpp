#include <GL/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"

int main(int argc, char** argv)
{
	Display display(800, 600, "Window");

	Vertex verticies[] = {	Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 1.0)),
							Vertex(glm::vec3(0.0, 0.5, 0.0),   glm::vec2(0.5, 0.0)),
							Vertex(glm::vec3(0.5, -0.5, 0.0),  glm::vec2(1.0, 1.0)) };

	Mesh mesh(verticies, sizeof(verticies) / sizeof(verticies[0]));
	Shader shader("./res/basicShader");
	Texture texture("./res/TriForce.jpg");

	while (!display.isClosed()){

		display.Clear(0.0f, 0.0f, 0.3f, 0.5f);
		shader.Bind();
		texture.Bind(0);
		mesh.Draw();
		display.swapBuffers();
	}

	return 0;
}