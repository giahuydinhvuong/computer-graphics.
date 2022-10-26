#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
int x[4];
int y[4];
struct LIST { 
	int x,y;
	struct LIST *next;
};
struct LIST *top;
void push(int x,int y){
	struct LIST *P;
	P=(LIST *) calloc(1,sizeof(LIST));
	P->x=x; P->y=y; P->next=NULL;
	if (top!=NULL) P->next=top;
	top=P;
}
void pop(int *x,int *y){
	struct LIST *P;
	P=top; top=top->next; *x=P->x; *y=P->y;
	free(P);
}
void BoundaryFill(int x,int y, float* fillColor, float* bc){
	float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(color[0]!=fillColor[0] || color[1]!=fillColor[1] || color[2]!=fillColor[2])){
    	glColor3f(fillColor[0],fillColor[1],fillColor[2]);
    	glPointSize(1);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        push(x,y);
	}
}
void BoundaryFill_Stack(int x0,int y0,float* fillColour,float* boundaryColour){

	int x,y;
	glColor3f(fillColour[0],fillColour[1],fillColour[2]);
	glPointSize(1);
    glBegin(GL_POINTS);
        glVertex2i(x0,y0);
    glEnd();
    glFlush();
	top=NULL;                     
	push(x0,y0);
	while(top!=NULL){
		pop(&x,&y);
		BoundaryFill (x-1,y, fillColour, boundaryColour);
		BoundaryFill (x+1,y,fillColour, boundaryColour);
		BoundaryFill (x,y+1,fillColour, boundaryColour);
		BoundaryFill (x,y-1, fillColour, boundaryColour);

	}
}
  
void readPoint(){
   int arr[8];
   ifstream is("ToMauVetDauLoang.txt");
   int cnt = 0;
   int j = 0;
   int num;
   // check that array is not already full
   while (cnt < arr[8] && is >> num)
   // and read integer from file
   arr[cnt++] = num;
   for (int i=0;i<8;i++) {
   	if (i%2==0) x[j] = arr[i];
   	else y[j++] = arr[i];
   	}
   cout<<"The integers are:"<<"\n";
   for (int i = 0; i < j; i++) {
      cout << x[i] <<' '<< y[i] <<'\n';
   }
   is.close();
}

void init()
{
    glClearColor(2.0,1.0,1.0,0.0);
    glOrtho(0,640,0,480,-1,1);
    readPoint();
}

void mouse(int btn, int state, int x, int y)
{
    y = 480-y;
    if(btn==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
            float bCol[] = {1,0,0};
            float color[] = {0,0,1};
            BoundaryFill_Stack(x,y,color,bCol);
        }
    }
}

void mydisplay(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(x[0],y[0]);
        glVertex2i(x[1],y[1]);
        glVertex2i(x[2],y[2]);
        glVertex2i(x[3],y[3]);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Boundary Fill - No Recursion");
    glutDisplayFunc(mydisplay);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
