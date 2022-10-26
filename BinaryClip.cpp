#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
#include <stdbool.h>
using namespace std;
bool drag = false;
float xmin=-100;    // Bien luu toa do 4 dinh hinh chu nhat
float ymin=-100;
float xmax=200;
float ymax=150;

struct Point {
	float x,y;
};
Point A,B;

void initGL(void)
{
    glClearColor(1,1,1,0);
    gluOrtho2D(-300,300,-300,300);
}

// Ve hinh chu nhat va doan thang
void display(Point A, Point B, bool clear)
{
   if (clear) glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINE_LOOP); //Ve hinh vuong
   		glVertex2i(xmin,ymin);
   		glVertex2i(xmin,ymax);
   		glVertex2i(xmax,ymax);
   		glVertex2i(xmax,ymin);
   glEnd();
   
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);  //Ve duong thang
   		glVertex2i(A.x,A.y);
   		glVertex2i(B.x,B.y);
   glEnd();

   glFlush();
}

void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

int code(Point A)  //Tinh Code cua diem
{
    int c=0;
    if(A.y>ymax)c|=8;
    if(A.y<ymin)c|=4;
    if(A.x>xmax)c|=2;
    if(A.x<xmin)c|=1;
    return c;
}

void swap (Point* A, Point* B) {
	Point tmp = *A;
	*A = *B;
	*B = tmp;
}	

void BinaryClip(Point A,Point B,bool clear){

	Point P,Q,M;
	cout<<code(A)<<" "<<code(B)<<" "<<(code(A) | code(B))<<" "<<(code(A) & code(B))<<"\n";
	if ((code(A) | code(B))==0) display(A,B,clear);
	if ((code(A) & code(B)) != 0) return;
	if ((code(A) != 0) && (code(B) == 0)) swap(&A,&B);
	if ((code(A) == 0) && (code(B) != 0)){
	
		P=A; Q=B;
		while ((fabs(P.x-Q.x)+fabs(P.y-Q.y)) > 2){
		
			M.x=(P.x+Q.x)/2; M.y=(P.y+Q.y)/2;
			if (code(M)==0) P=M;
			else Q=M;
		
		}
		display(A,P,clear);
	}
	if (((code(A) != 0) && (code(B) != 0)) && ((code(A) & code(B))==0)){
	
		P=A; Q=B;
		M.x=(P.x+Q.x)/2; M.y=(P.y+Q.y)/2;
		while ((code(M)!=0) && ((fabs(P.x-Q.x)+fabs(P.y-Q.y)) > 2)){
		
			if ((code(P) & code(M))!=0) P=M;
			else Q=M;
			M.x=(P.x+Q.x)/2; M.y=(P.y+Q.y)/2;
		
		}
		if (code(M)==0){
			
			glClear(GL_COLOR_BUFFER_BIT);
			BinaryClip (P,M,false);
			BinaryClip (M,Q,false);
		
		}	
	}
	
}

void mykey(unsigned char key,int x,int y)
{
    if(key=='c')//Nhan phim c de xen (ve lai doan thang)
    { 
        BinaryClip(A,B,true);
        glFlush();
    }
}

void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
            if (!drag) {
            	drag = true;
            	A.x = (float)x-300;
            	A.y = (float)-(y-300);
            	//cout<<xdA<<" "<<ydA<<"\n";
			}
        }
        if(state==GLUT_UP)
        {
            if (drag) {
            	drag = false;
            	display(A,B,true);
			}
        }
    }
}

void mouseMove(int x, int y) {
	if (drag) {
		B.x = (float)x-300;
        B.y = (float)-(y-300);
        glClear(GL_COLOR_BUFFER_BIT);
   		glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINES);  //Ve duong thang
	   		glVertex2i(A.x,A.y);
	   		glVertex2i(B.x,B.y);
	   glEnd();
	   glFlush();
	}
	
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("DEMO XET DOAN THANG BANG HCN - Binary Clip");
    glutDisplayFunc(mydisplay);
    glutKeyboardFunc(mykey);
    glutMouseFunc(mouse); 
	glutMotionFunc(mouseMove);
    initGL();
    glutMainLoop();
    return 0;
}

