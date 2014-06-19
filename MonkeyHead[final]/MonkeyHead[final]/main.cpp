#include <GL/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include "Display.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"
#include "Transform.h"
#include "Camera.h"

static const int DISPLAY_WIDTH = 800;
static const int DISPLAY_HEIGHT = 600;

int main(int argc, char** argv)
{
	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL");


	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0)),
						  Vertex(glm::vec3(0.0, 0.5, 0.0), glm::vec2(0.5, 1.0)),
						  Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1.0, 0.0)), };

	unsigned int indices[] = { 0, 1, 2 };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
	Mesh mesh2("./res/monkey3.obj");
	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");
	Transform transform;
	Camera camera(glm::vec3(0, 0, -4), 70.0f, (float)DISPLAY_WIDTH / (float)DISPLAY_HEIGHT, 1.0f, 1000.0f);

	float counter = 0.0f;


	while (!display.isClosed()){

		//display.Clear(0.8f, 0.4f, 0.4f, 0.8f);
		display.Clear(0.0f, 0.0f, 0.0f, 0.8f);
		
		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);
		float absSinCounter = abs(sinCounter);

		transform.GetPos().x = sinCounter;
		transform.GetPos().z = cosCounter;
		transform.GetRot().x = counter * 50;
		transform.GetRot().y = counter * 50;
		transform.GetRot().z = counter * 50;
		//transform.GetScale().x = absSinCounter;
		//transform.GetScale().y = absSinCounter;
		//transform.SetScale(glm::vec3(sinCounter, sinCounter, sinCounter));

		shader.Bind();
		shader.Update(transform, camera);
		texture.Bind(0);
		mesh.Draw();
		mesh2.Draw();

		display.swapBuffers();
		counter += 0.001f;
	}

	std::cin.get();
	return 0;
}