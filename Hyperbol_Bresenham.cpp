#include <GL/glut.h>
#include <iostream>
using namespace std;
void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-160,160,-120,120,-1,1);	
}

void draw2point(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc - x, yc - y);
	glEnd();
}
void hyperbol(int xc, int yc, int xBound, int yBound)	
{	 
    glPointSize(2);
	
	int x = 30;
	int y = 30;
	double P = (double) (2*x-1)-1800/(y+1);
	//cout<<x<<" "<<y<<" "<<P<<"\n";
	while (y<=yBound)
	{
		draw2point(xc, yc, x,y);
		if (P<0) P += (double) 1800/((y+2)*(y+1));
    	else {
    		P += (double) 1800/((y+2)*(y+1)) - 2;
    		x--;
		}
		y++;
		draw2point(xc, yc, x,y);
		//cout<<(double)900/y<<" "<<y<<" "<<P<<"\n";
	}
	x = 30; y = 30; P = (double) -1800/(x+1)+2*y-1;
	
	//cout<<x<<" "<<y<<" "<<P<<"\n";
	while (x<=xBound)
	{
		draw2point(xc, yc, x,y);
		if (P<0) P += (double) 1800/((x+2)*(x+1));
    	else {
    		P += (double) 1800/((x+2)*(x+1)) - 2;
    		y--;
		}
		x++;
		draw2point(xc, yc, x,y);
		//cout<<x<<" "<<(double)900/x<<" "<<P<<"\n";
	}
}

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glViewport(0,0,640,480);
	hyperbol(0,0,160,120);  // Ve hyperbol y = 900/x
	glFlush();

}

int main(int argc, char** argv){
	int mode = GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO THUAT TOAN VE HYPERBOL - BRESENHAM");
	initGL();
	glutDisplayFunc(mydisplay);    
	glutMainLoop();
}

