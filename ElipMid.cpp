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
void EllipsMidpoint(int xc,int yc,int a,int b )	
{	 
   	
   	int x = 0;
	int y = b; 
	
	float x0 = a*a/sqrt(a*a + b*b); 
	float P = b*b - a*a*b +a*a/4;
	draw4point(xc,yc,x,y);
	while (x <= x0) 
    	{
		if (P <0)	
           P += (b*b)*(2*x + 3);
            
		else
           {	
            
            P += (b*b)*(2*x+3) - 2*a*a*(y-1);
		    y--;
		   }
		x++;
        draw4point(xc,yc,x,y);
		}
	
	x=a;
	y=0;
	
	P = a*a - b*b*a +b*b/4;
	draw4point(xc,yc,x,y);
	while (x > x0) 
    	{
		if (P <0)	
            P +=(a*a)*(2*y + 3);
		else
           {	
            P += (a*a)*(2*y+3) - 2*b*b*(x-1);
            
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
			EllipsMidpoint(P[n-2].x, P[n-2].y, ra, rb);
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
	glutCreateWindow("VE ELIP - MIDPOINT");
	gluOrtho2D(-350, 300, -350, 300);
	initGL();
	glutDisplayFunc(mydisplay);
	glutMouseFunc(MouseEventHandler);
	glutMainLoop();
}

