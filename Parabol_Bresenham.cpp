#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;
void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-80,80,-20,100,-1,1);	
}

void draw2point(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x + xc, y + yc);
		glVertex2i(xc - x, yc + y);
	glEnd();
}
void parabol(int xc, int yc, int bound)	
{	 
    glPointSize(4);
    int x = 0;
    int y = 0;
    double P = (double)1/2-1;
    //cout<<x<<" "<<y<<"\n";
    while (x/2<1 && y<=bound) {
    	draw2point(xc, yc, x,y);
    	if (P<0) P += x+3/2;
    	else {
    		P += x+3/2-2;
    		y++;
		}
		x++;
		//draw2point(xc, yc, x,y);
		cout<<x<<" "<<(double)x*x/4<<"\n";
	}
	while (y<=bound) {
		draw2point(xc, yc, x,y);
		if (P<0) P += 2*(sqrt(4*(y+2))-sqrt(4*(y+1)));
		else {
			P += 2*(sqrt(4*(y+2))-sqrt(4*(y+1))-1);
			x++;
		}
		y++;
		//draw2point(xc, yc, x,y);
		cout<<(double)2*sqrt((double)y)<<" "<<y<<"\n";
	}
    
}

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glViewport(0,0,640,480);
	parabol(0,0, 94);  // Ve parabol y = (x^2)/4
	glFlush();

}

int main(int argc, char** argv){
	int mode = GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO THUAT TOAN VE PARABOL - BRESENHAM");
	initGL();
	glutDisplayFunc(mydisplay);    
	glutMainLoop();
}

