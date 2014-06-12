#include <iostream>
#include <GL/glut.h>

using namespace std;

void changeViewPort(int w, int h) {
	glViewport(0, 0, w, h);
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("GL Hello World");
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);

	GLenum
}