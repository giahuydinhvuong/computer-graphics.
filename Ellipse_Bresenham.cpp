#include <GL/glut.h>
#include <iostream>
#include <stdbool.h>
#include <cmath>
using namespace std;
bool drag = false;
int xc1 = 0;
int yc1 = 0;
int xr1 = 0;
int yr1 = 0;
void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-320,320,-240,240,-1,1);	
}
void draw4point(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
		 
		glVertex2i(x + xc, y + yc);
		glVertex2i(x + xc,-y + yc);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc - x, yc + y);

	glEnd();
	glFlush();
}
void EllipsBresenham(int xc,int yc,double a, double b )	
{	 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
   	
   	int x = 0;
	int y = b; 
	float x0 = a*a/sqrt(a*a + b*b); 
	float P = a*a*(1-2*b)+ b*b;
	draw4point(xc,yc,x,y);
	while (x <= x0) {
		if (P <0) P += (2*b*b)*(2*x + 3);
        else {	
            P += (2*b*b)*(2*x+3) + 4*a*a*(1-y);
		    y--;
		}
		x++;
        draw4point(xc,yc,x,y);
	}
	x = a;
	y = 0;
	P = b*b*(1-2*a)+ a*a;
	draw4point(xc,yc,x,y);
	while (x > x0) {
		if (P <0) P +=(2*a*a)*(2*y + 3);
		else {	
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
	glViewport(0,0,640,480);
	glFlush();

}

void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
            if (!drag) {
            	drag = true;
            	xc1 = x-320;
            	yc1 = -(y-240);
            	cout<<xc1<<" "<<yc1<<"\n";
			}
        }
        if(state==GLUT_UP)
        {
            if (drag) {
            	drag = false;
			}
        }
    }
}

void mouseMove(int x, int y) {
	if (drag) {
		xr1 = x-320;
        yr1 = -(y-240);
        cout<<xr1<<" "<<yr1<<"\n";
        double a = fabs(xr1-xc1);
        double b = fabs(yr1-yc1);
        EllipsBresenham(xc1, yc1, a, b); //Tâm C(xc1,yc1) truc lon a, truc nho b
	}
	
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO THUAT TOAN VE DUONG ELLIPSE - BRESENHAM");
	initGL(); 
	glutDisplayFunc(mydisplay);  
	glutMouseFunc(mouse); 
	glutMotionFunc(mouseMove); 
	glutMainLoop();
}

