#include <GL/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char** argv)
{
	Display display(800, 600, "Window");

	Vertex verticies[] = {	Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 1.0)),
							Vertex(glm::vec3(0.0, 0.5, 0.0),   glm::vec2(0.5, 0.0)),
							Vertex(glm::vec3(0.5, -0.5, 0.0),  glm::vec2(1.0, 1.0)) };

	Mesh mesh(verticies, sizeof(verticies) / sizeof(verticies[0]));
	Shader shader("./res/basicShader");
	Texture texture("./res/TriForce.jpg");
	Transform transform;
	Camera camera(glm::vec3(0, 0, -3), 70.0f, float(WIDTH) / float(HEIGHT), 0.01f, 1000.0f);

	float counter = 0.0f;

	while (!display.isClosed()){

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		display.Clear(0.0f, 0.0f, 0.3f, 0.5f);
		shader.Bind();
		shader.Update(transform, camera);
		texture.Bind(0);
		mesh.Draw();
		display.swapBuffers();

		transform.GetPos().x = sinCounter;
		transform.GetRot().z = counter * 50;
		transform.GetRot().y = counter * 50;
		transform.GetRot().x = counter * 50;
		//transform.SetScale(glm::vec3(cosCounter,cosCounter,cosCounter));
		counter += 0.01f;
	}

	return 0;
}