#include <GL/glew.h>
#include <iostream>
#include "display.h"

#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 600

int main()
{
	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL");
	
	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.0f, 1.0f);
		display.Update();
	}

	return 0;
}