#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int x, y;
} Point;

Point P[10];
int n = -1;
void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
}

void lineMidPoint(int x1, int y1, int x2, int y2) {
	int x, y, Dx, Dy, p;
	Dx = abs(x2 - x1);
	Dy = abs(y2 - y1);
	p = 2 * Dy - Dx;
	x = x1;
	y = y1;

	int x_unit = 1, y_unit = 1;

		if (x2 - x1 < 0)
			x_unit = -x_unit;
	if (y2 - y1 < 0)
		y_unit = -y_unit;
	glBegin(GL_POINTS);
	if (x1 == x2)   // ve duong thang
	{
		while (y != y2 + 1)
		{
			y += y_unit;
			glVertex2i(x, y);
		}
	}

	else if (y1 == y2)  
	{
		while (x != x2 + 1)
		{
			x += x_unit;
			glVertex2i(x, y);
		}
	}
	// ve duong xien
	else {
		while (x != x2) {
			if (p < 0) p += 2 * Dy;
			else {
				p += 2 * (Dy - Dx);
				y += y_unit;
			}
			x += x_unit;
			glVertex2i(x, y);
		}
	}
	glEnd();
}

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 640, 480);
	glFlush();

}
void MouseEventHandler(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		n++;
		P[n].x = x - 350;
		P[n].y = 350 - y;
		printf("\n n=%i x=%d y=%d", n, P[n].x, P[n].y);
		if (n%2!=0 && n!=0){
			glColor3f(0.0, 0.0, 0.0);
			lineMidPoint(P[(n - 1)].x, P[(n - 1)].y, P[n].x, P[n].y);
			glFlush();
			glutPostRedisplay();
		}
	}
}
int main(int argc, char** argv) {
	int mode = GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("VE DOAN THANG - MIDPOINT");
	gluOrtho2D(-350, 300, -350, 300);
	initGL();
	glutDisplayFunc(mydisplay);
	glutMouseFunc(MouseEventHandler);
	glutMainLoop();
}
