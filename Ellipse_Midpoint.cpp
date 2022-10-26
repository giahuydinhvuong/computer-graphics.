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
	float a2 = a*a; 
	float b2 = b*b;
	float x0 = (int)(a2/sqrt(a2+b2)); 
	float y0 = (int)(b2/sqrt(a2+b2));
	float p = b2-a2*b+(1/4)*a2;
	while (x <= x0){
		draw4point(xc,yc,x,y);
		if (p<0) p+=(2*x+3)*b2;
		else { 
			p+=(2*x+3)*b2-2*a2*(y-1);
			y--;
		}
		x++;
	}
	x = a; 
	y = 0; 
	p = a2-a*b2+(1/4)*b2;
	while (y <= y0){
		draw4point(xc,yc,x,y);
		if (p<0) p += a2*(2*y+3);
		else {		
			p+=(2*y+3)*a2-2*b2*(x-1);
			x--;	
		}
		y++;
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

