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
void draw4point(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
		 
		glVertex2i(x + xc, y + yc);
		glVertex2i(x + xc,-y + yc);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc - x, yc + y);

	glEnd();
}
void EllipsBresenham(int xc,int yc,int a, int b )	
{	 
   	
   	int x = 0;
	int y = b; 
	
	float x0 = a*a/sqrt(a*a + b*b); 
	float P = a*a*(1-2*b)+ b*b;
	draw4point(xc,yc,x,y);
	while (x <= x0) 
    	{
		if (P <0)	
           P += (2*b*b)*(2*x + 3);
            
		else
           {	
            
            P += (2*b*b)*(2*x+3) + 4*a*a*(1-y);
		    y--;
		   }
		x++;
        draw4point(xc,yc,x,y);
		}
	
	x=a;
	y=0;
	
	P=b*b*(1-2*a)+ a*a;
	draw4point(xc,yc,x,y);
	while (x > x0) 
    	{
		if (P <0)	
            P +=(2*a*a)*(2*y + 3);
		else
           {	
            P += (2*a*a)*(2*y + 3) + 4*b*b*(1-x);
            
		    x--;
		   }
		y++;
        draw4point(xc,yc,x,y);
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
		if (n == 2){
			glColor3f(0.0, 0.0, 0.0);
			int ra = sqrt((P[(n -1)].x - P[(n - 2)].x)*(P[(n -1)].x - P[(n - 2)].x) + (P[(n -1)].y - P[(n - 2)].y)*(P[(n -1)].y - P[(n - 2)].y));
			int rb = sqrt((P[n].x - P[(n - 2)].x)*(P[n].x - P[(n - 2)].x) + (P[n].y - P[(n - 2)].y)*(P[n].y - P[(n - 2)].y));
			EllipsBresenham(P[n-2].x, P[n-2].y, ra, rb);
			// EllipsBresenham(0, 0, 300,200);
			glFlush();
			glutPostRedisplay();
			n = -1;
			printf("\n %d %d", ra, rb);
		}
	}
}

int main(int argc, char** argv){
	int mode = GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("VE ELIP - BRESENHAM");
	gluOrtho2D(-350, 300, -350, 300);
	initGL();
	glutDisplayFunc(mydisplay);
	glutMouseFunc(MouseEventHandler);
	glutMainLoop();
}

