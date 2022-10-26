#include <GL/glut.h>
#include <iostream>
#include <cmath>
#define PI 3.1415926535
using namespace std;
void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-240,240,-60,60,-1,1);	
}

void draw2point(int xc, int yc, int x, int y, int xBound)
{
	int k = 0;
	glBegin(GL_POINTS);
	while(xc+x+k*40*PI <= xBound) {
		glVertex2i(xc + x + k*40*PI, yc + y);
		glVertex2i(xc - x - k*40*PI, yc - y);
		k++;
	}
	glEnd();
}
void hyperbol(int xc, int yc, int xBound)	
{	 
    glPointSize(3);
	int x = 0;
	int y = 0;
	double P = (double) 20*sin(((double)x+1)/20)-y-0.5;
	//cout<<x<<" "<<y<<" "<<P<<"\n";
	while(x<PI*10) {
		draw2point(xc, yc, x,y, xBound);
		if (P<0) P += (double) 20*sin(((double)x+2)/20)-20*sin(((double)x+1)/20);
    	else {
    		P += (double) 20*sin(((double)x+2)/20)-20*sin(((double)x+1)/20)-1;
    		y++;
		}
		x++;
		draw2point(xc, yc, x,y, xBound);
		//cout<<(double)900/y<<" "<<y<<" "<<P<<"\n";
	}
	//x = PI*10; y = 20;
	P = (double) 20*sin(((double)x+1)/20)-y+0.5;
	while(x<PI*30) {
		if (P<0) P -= (double) 20*sin(((double)x+2)/20)-20*sin(((double)x+1)/20);
    	else {
    		P -= (double) 20*sin(((double)x+2)/20)-20*sin(((double)x+1)/20)+1;
    		y--;
		}
		x++;
		draw2point(xc, yc, x,y, xBound);
		//cout<<(double)900/y<<" "<<y<<" "<<P<<"\n";
	}
	//x = PI*30; y = -20;
	P = (double) 20*sin(((double)x+1)/20)-y-0.5;
	while(x<PI*40) {
		if (P<0) P += (double) 20*sin(((double)x+2)/20)-20*sin(((double)x+1)/20);
    	else {
    		P += (double) 20*sin(((double)x+2)/20)-20*sin(((double)x+1)/20)-1;
    		y++;
		}
		x++;
		draw2point(xc, yc, x,y, xBound);
		//cout<<(double)900/y<<" "<<y<<" "<<P<<"\n";
	}
	
}

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glViewport(0,0,640,160);
	hyperbol(0,0,240);  // y = 20sin(x/20)
	glFlush();

}

int main(int argc, char** argv){
	int mode = GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	
	glutInitWindowSize(640, 160);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO THUAT TOAN VE SIN(X) - MIDPOINT");
	initGL();
	glutDisplayFunc(mydisplay);    
	glutMainLoop();
}

