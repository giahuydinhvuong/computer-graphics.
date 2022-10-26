#include <GL/glut.h>
#include <iostream>
#include <stdbool.h>
#include <math.h>
using namespace std;
bool drag = false;
int xc1 = 0;
int yc1 = 0;
int xr1 = 0;
int yr1 = 0;
void initGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-320,320,-240,240,-1,1);	
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
	glFlush();
}
void CircleMidpoint(int xc,int yc,int R )	
{	 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
   	float P;
	int y = R; 
	int x = 0;
	P = 5/4 - R;
	draw8point(xc,yc,x,y);
	while (x < y) 
    	{
		if (P <0)	// Chon diem P
            {
			P += 2*x + 3;
            
            }
        else      // Chon diem S
            {	
            P += 2*(x - y) + 5;
            y--;
	        }
   
		x++;
        draw8point(xc,yc,x,y);
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
        int R = (int)sqrt(pow(xr1-xc1,2)+pow(yr1-yc1,2));
        CircleMidpoint(xc1, yc1, R); //T�m C(xc1,yc1) b�n k�nh R
	}
	
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO THUAT TOAN VE DUONG TRON - MIDPOINT");
	initGL(); 
	glutDisplayFunc(mydisplay);  
	glutMouseFunc(mouse); 
	glutMotionFunc(mouseMove); 
	glutMainLoop();
}

