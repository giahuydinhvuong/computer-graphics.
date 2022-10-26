#include <GL/glut.h>
#include <iostream>
#include <stdbool.h>
#include <cmath>
using namespace std;
bool drag = false;
int a1 = 0;
int b1 = 0;
int a2 = 0;
int b2 = 0;
void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=1,G=1,B=1, anpha=1
	glOrtho(-320,320,-240,240,-1,1);	
}
void LineMidPoint(int x1,int y1,int x2,int y2)	
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);  //R=1,G=1,B=1 ==> Red
   	
    glBegin(GL_POINTS);
    int x, y, Dx, Dy, p;
    Dx = abs(x2 - x1);
    Dy = abs(y2 - y1);
    if (Dy>Dx) p = 2*Dx - Dy;
    else p = 2*Dy - Dx;
    x = x1;
    y = y1;
 
    int x_unit = 1, y_unit = 1;
 
    if (x2 - x1 < 0)
        x_unit = -x_unit;
    if (y2 - y1 < 0)
        y_unit = -y_unit;
 	
 	if (x1 == x2 && y1 == y2) glVertex2i(x,y);
    else if (x1 == x2)  
    {
        while (y != y2)
        {
            y += y_unit;
            glVertex2i(x,y);
        }
    } else if (y1 == y2) {
        while (x != x2)
        {
            x += x_unit;
            glVertex2i(x,y);
        }
    } else {          
        glVertex2i(x,y);
        while(x != x2 && Dy<Dx){
            if (p<0) p += 2*Dy;
            else{
                p += 2*(Dy-Dx);
                y += y_unit;
            }
            x += x_unit;
            glVertex2i(x,y);
        }
        while(y != y2 && Dx<Dy){
            if (p<0) p += 2*Dx;
            else{
                p += 2*(Dx-Dy);
                x += x_unit;
            }
            y += y_unit;
            glVertex2i(x,y);
        }
    }
    
    glEnd();
    glFlush();
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
            	a1 = x-320;
            	b1 = -(y-240);
            	cout<<a1<<" "<<b1<<"\n";
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
		a2 = x-320;
        b2 = -(y-240);
        cout<<a2<<" "<<b2<<"\n";
        LineMidPoint(a1, b1, a2, b2);
	}
	
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO THUAT TOAN VE DOAN THANG - MIDPOINT");
	initGL(); 
	glutDisplayFunc(mydisplay);  
	glutMouseFunc(mouse); 
	glutMotionFunc(mouseMove); 
	glutMainLoop();
}

