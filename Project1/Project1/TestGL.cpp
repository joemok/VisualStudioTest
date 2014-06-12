#include <string>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
using namespace std;

typedef vector<int> list;
vector<list> ls, cs, es;
int old_x, old_y, new_x, new_y, cx, cy, cr, xc, yc, rx, ry;
int mouse_type;
bool keystates[256];
bool mouseButtonStates[3];

void line(int x1, int y1, int x2, int y2) {

	glBegin(GL_POINTS);
	if (x1 == x2 && y1 == y2) {
		glVertex2i(x1, y1);
		return;
	}

	if (x1 > x2) {
		swap(x1, x2);
		swap(y1, y2);
	}

	glVertex2d(x1, y1);
	int dy = abs(y2 - y1);
	int dx = abs(x2 - x1);
	if (dx >= dy) {
		int incy = (dy != 0 ? dy / (y2 - y1) : 0);
		int p = 2 * dy - dx;
		int dy2 = 2 * dy;
		int dd2 = 2 * (dy - dx);
		int x, y = y1;
		for (x = x1 + 1; x <= x2; ++x) {
			if (p < 0) {
				glVertex2i(x, y);
				p += dy2;
			}
			else {
				y += incy;
				glVertex2i(x, y);
				p += dd2;
			}
		}
	}
	else {
		if (y1 > y2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		int incx = (dx != 0 ? dx / (x2 - x1) : 0);
		int p = 2 * dx - dy;
		int dx2 = 2 * dx;
		int dd2 = 2 * (dx - dy);
		int x = x1, y;
		for (y = y1 + 1; y <= y2; ++y) {
			if (p < 0) {
				glVertex2i(x, y);
				p += dx2;
			}
			else {
				x += incx;
				glVertex2i(x, y);
				p += dd2;
			}
		}
	}
	glEnd();
}

/* 中点圆算法 */
void circle(int cx, int cy, int r) {
	int x = 0, y = r;
	float p = 1.25 - r;

	while (x <= y) {
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_POINTS);
		glVertex2i(cx + x, cy + y);
		glVertex2i(cx - x, cy + y);
		glVertex2i(cx - x, cy - y);
		glVertex2i(cx + x, cy - y);
		glVertex2i(cx + y, cy + x);
		glVertex2i(cx - y, cy + x);
		glVertex2i(cx - y, cy - x);
		glVertex2i(cx + y, cy - x);
		glEnd();

		if (p < 0) {
			++x;
			p += 2 * x + 1;
		}
		else {
			p += 2 * x - 2 * y + 5;
			++x;
			--y;
		}
	}
}

void ellipse(float xc, float yc, float rx, float ry) {
	float rxSq = rx * rx;
	float rySq = ry * ry;
	float x = 0, y = ry, p;
	float px = 0, py = 2 * rxSq * y;

	//Region 1
	p = rySq - (rxSq * ry) + (0.25 * rxSq);

	while (px < py) {
		glBegin(GL_POINTS);
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc - x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glEnd();

		x++;
		px = px + 2 * rySq;

		if (p < 0) {
			p = p + rySq + px;
		}

		else {
			y--;
			py = py - 2 * rxSq;
			p = p + rySq + px - py;
		}

	}

	//Region 2
	p = rySq * (x + 0.5) * (x + 0.5) + rxSq * (y - 1) * (y - 1) - rxSq * rySq;

	while (y > 0) {
		glBegin(GL_POINTS);
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc - x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glEnd();

		y--;
		py = py - 2 * rxSq;

		if (p > 0) {
			p = p + rxSq - py;
		}

		else {
			x++;
			px = px + 2 * rySq;
			p = p + rxSq - py + px;
		}

	}

}

void draw() {
	int i;
	for (i = 0; i < ls.size(); ++i)
		line(ls[i][0], ls[i][1], ls[i][2], ls[i][3]);
	for (i = 0; i < cs.size(); ++i)
		circle(cs[i][0], cs[i][1], cs[i][2]);
	for (i = 0; i < es.size(); ++i)
		ellipse(es[i][0], es[i][1], es[i][2], es[i][3]);

	if (mouse_type == 1)
		line(old_x, old_y, new_x, new_y);
	if (mouse_type == 2)
		ellipse(xc, yc, rx, ry);
	if (mouse_type == 3)
		circle(cx, cy, cr);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3i(0, 0, 0);
	draw();
	glutSwapBuffers();
}

void keyboardDown(unsigned char key, int x, int y) {

	keystates[key] = true;

}

void keyboardUp(unsigned char key, int x, int y) {

	keystates[key] = false;
}

void mouseClick(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN) {
		mouseButtonStates[button] = true;
	}
	else {
		mouseButtonStates[button] = false;
	}

	if (keystates['e'] || keystates['E'] && state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			std::cout << "Drawing Ellipse" << std::endl;
		}
	}

	if (keystates['l'] || keystates['L'] && state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{

			std::cout << "Drawing Line" << std::endl;
		}
	}

}

void mouseMotion(int x, int y)
{
	if (mouseButtonStates[GLUT_LEFT_BUTTON] == true)
	{
		if (keystates['r'] || keystates['R'])
		{
			std::cout << "Rotating object" << std::endl;
		}

		if (keystates['t'] || keystates['T'])
		{
			std::cout << "Translating object" << std::endl;
		}

		if (keystates['s'] || keystates['S'])
		{
			std::cout << "Scaling object" << std::endl;
		}

	}
}


void mouseclick(int button, int state, int x, int y) {

	cout << "(" << x << "," << y << ")";
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			cout << "左键被按下";
			old_x = x;
			old_y = 600 - y;
			mouse_type = 1;
		}
		else if (state == GLUT_UP) {
			cout << "左键被松开";
			list l;
			l.push_back(old_x);
			l.push_back(old_y);
			l.push_back(x);
			l.push_back(600 - y);
			ls.push_back(l);
			mouse_type = 0;
			glutPostRedisplay();
			for (int i = 0; i < ls.size(); ++i)
				cout << endl << "line_" << i << ": " << ls[i][0] << "," << ls[i][1] << "   " << ls[i][2] << "," << ls[i][3];
		}
		break;

	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN) {
			cout << "右键被按下";
			xc = x;
			yc = 600 - y;
			mouse_type = 2;
		}
		else if (state == GLUT_UP) {
			cout << "右键被松开";
			list l;
			l.push_back(xc);
			l.push_back(yc);

			rx = int(sqrt(double(x - xc) * (x - xc) + (600 - y - yc) * (600 - y - yc)) + 0.5);
			ry = int(sqrt(double(600 - x - y) * (600 - x - xc) + (y - yc) * (y - yc)) + 0.5);

			l.push_back(rx);
			l.push_back(ry);
			es.push_back(l);
			mouse_type = 0;
			glutPostRedisplay();
			for (int i = 0; i < es.size(); ++i)
				cout << endl << "ellipse_" << i << ": " << es[i][0] << "," << es[i][1] << "   " << es[i][2] << "," << es[i][3];
		}
		break;

	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			cout << "右键被按下";
			cx = x;
			cy = 600 - y;
			mouse_type = 3;
		}
		else if (state == GLUT_UP) {
			cout << "右键被松开";
			list l;
			l.push_back(cx);
			l.push_back(cy);
			cr = int(sqrt(double(x - cx) * (x - cx) + (600 - y - cy) * (600 - y - cy)) + 0.5);
			l.push_back(cr);
			cs.push_back(l);
			mouse_type = 0;
			glutPostRedisplay();
			for (int i = 0; i < cs.size(); ++i)
				cout << endl << "circle_" << i << ": " << cs[i][0] << "," << cs[i][1] << "   " << cs[i][2];
		}
		break;
	}
}

void screenmotion(int x, int y) {
	if (mouse_type == 1) {
		new_x = x;
		new_y = 600 - y;

		cout << endl << "new-line:" << old_x << "," << old_y << "   " << new_x << "," << new_y << endl;

	}
	else if (mouse_type == 3) {
		cr = int(sqrt(double(x - cx) * (x - cx) + (600 - y - cy) * (600 - y - cy)) + 0.5);

		cout << endl << "new-circle: " << cx << "," << cy << "   " << cr << endl;

	}
	else if (mouse_type == 2) {
		rx = int(sqrt(double(x - xc) * (x - xc) + (600 - y - yc) * (600 - y - yc)) + 0.5);
		ry = int(sqrt(double(600 - x - y) * (600 - x - xc) + (y - yc) * (y - yc)) + 0.5);

		cout << endl << "new-ellipse: " << xc << "," << yc << "   " << rx << "," << ry << endl;
	}

	glutPostRedisplay();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0, 600, 0.0, 601);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 50);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Drawing");
	init();
	glutDisplayFunc(display);
	glutMotionFunc(screenmotion);
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutMouseFunc(mouseclick);
	glutMainLoop();
	return 0;
}
