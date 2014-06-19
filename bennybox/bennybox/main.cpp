#include <GL/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"

#define WIDTH 800
#define HEIGHT 600
 
int main(int argc, char** argv)
{
	Display W(WIDTH, HEIGHT, "Window");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0)),
						  Vertex(glm::vec3(0.0, 0.5, 0.0), glm::vec2(0.5, 1.0)),
						  Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1.0, 0.0)), };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");
	Camera camera(glm::vec3(0, 0, -2), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
	Transform transform;

	float counter = 0.0f;

	while (!W.isClosed()){

		W.Clear(0.0f, 0.3f, 0.7f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPos().x = sinCounter;
		transform.GetPos().z = cosCounter;
		transform.GetRot().x = counter * 50;
		transform.GetRot().y = counter * 50;
		transform.GetRot().z = counter * 50;
		//transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

		shader.Bind();
		texture.Bind(0);
		shader.Update(transform, camera);
		mesh.Draw();

		W.swapBuffers();
		counter += 0.001f;
	}

	std::cin.get();
	return 0;
}