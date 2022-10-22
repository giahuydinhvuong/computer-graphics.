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

void draw8point(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc + y, yc + x);
		glVertex2i(xc + y, yc - x);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc - y, yc - x);
		glVertex2i(xc - y, yc + x);
		glVertex2i(xc - x, yc + y);
	glEnd();
}
void CircleBres(int xc,int yc,int R )	
{	 
   	int p ;
	int y = R ; 
	int x = 0;
	p = 3 - 2*R;
	draw8point(xc,yc,x,y);
	while (x < y) 
    	{
		if (p <0)	
            p +=4*x+6;
		else
            {	
              p += 4*(x-y)+10;
		      y--;
		    }
		x++;
        draw8point(xc,yc,x,y);
		}
}

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 640, 480);
	glFlush();

}
void MouseEventHandler(int button, int state, int x, int y )
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		n++;
		P[n].x = x - 350;
		P[n].y = 350 - y;
		printf("\n n=%i x=%d y=%d", n, P[n].x, P[n].y);
		if (n%2!=0 && n!=0){
			glColor3f(0.0, 0.0, 0.0);
			int r = sqrt((P[n].x - P[(n - 1)].x)*(P[n].x - P[(n - 1)].x) + (P[n].y - P[(n - 1)].y)*(P[n].y - P[(n - 1)].y));
			CircleBres(P[(n - 1)].x, P[(n - 1)].y, r);
			glFlush();
			glutPostRedisplay();
			printf("\n %d ", r);
		}
	}
}


int main(int argc, char** argv){
	int mode = GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("VE DUONG TRON - BRESENHAM");
	gluOrtho2D(-350, 300, -350, 300);
	initGL();
	glutDisplayFunc(mydisplay);
	glutMouseFunc(MouseEventHandler);
	glutMainLoop();
}

