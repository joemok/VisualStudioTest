#include <iostream>
#include <SDL/SDL.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

static const int DISPLAY_WIDTH = 1600;
static const int DISPLAY_HEIGHT = 900;

int main(int argc, char** argv)
{ 
	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL");

	Vertex vertices[] =
	{
		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 1), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(1, -1, -1), glm::vec2(1, 1), glm::vec3(0, 0, -1)),

		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 0), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(0, 0), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(0, 1), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 1), glm::vec3(0, 0, 1)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(0, 1), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 1), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 0), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(1, -1, -1), glm::vec2(0, 0), glm::vec3(0, -1, 0)),

		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 1), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(1, 1), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(1, 0), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 0), glm::vec3(0, 1, 0)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 1), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 0), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(0, 0), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 1), glm::vec3(-1, 0, 0)),

		Vertex(glm::vec3(1, -1, -1), glm::vec2(1, 1), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 0), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(0, 0), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 1), glm::vec3(1, 0, 0)),
	};

	unsigned int indices[] = {0, 1, 2,
							  0, 2, 3,

							  6, 5, 4,
							  7, 6, 4,

							  10, 9, 8,
							  11, 10, 8,

							  12, 13, 14,
							  12, 14, 15,

							  16, 17, 18,
							  16, 18, 19,

							  22, 21, 20,
							  23, 22, 20
	                          };

	//Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
	//Mesh monkey("./res/monkey3.obj");
	Mesh lamp("./res/lamp.obj");
	//Mesh mario("./res/mario_obj.obj");
	//Mesh airboat("./res/airboat.obj");
	//Mesh cessna("./res/cessna.obj");
	//Mesh pl("./res/power_lines.obj");
	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");
	Transform transform;
	Camera camera(glm::vec3(0.0f, 2.0f, -10.0f), 70.0f, (float)DISPLAY_WIDTH/(float)DISPLAY_HEIGHT, 0.1f, 100.0f);

	SDL_Event e;
	bool isRunning = true;
	float counter = 0.0f;
	while(isRunning)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
				isRunning = false;
		}

		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);

		float sinCounter = sinf(counter);
		float absSinCounter = abs(sinCounter);

		//transform.GetPos()->x = sinCounter;
		transform.GetRot()->y = counter * 100;
		//transform.GetRot()->z = counter * 100;
		//transform.GetScale()->x = absSinCounter;
		//transform.GetScale()->y = absSinCounter;

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //Turn on wireframe mode
		glEnable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(0.85, 0.85);

		shader.Bind();
		//texture.Bind();
		shader.Update(transform, camera);
		lamp.Draw();
		//monkey.Draw();
		//mesh.Draw();

		display.SwapBuffers();
		SDL_Delay(1);
		counter += 0.001f;
	}

	return 0;
}
