#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;
int xmin=-100;    // Bien luu toa do 4 dinh hinh chu nhat
int ymin=-100;
int xmax=200;
int ymax=150;
int xdA,ydA,xdB,ydB; // Bien luu toa do diem A v? B

typedef struct {
	int x, y;
} Point;

Point P[10];
int n = -1;
void initGL(void)
{
    glClearColor(1,1,1,0);
    gluOrtho2D(-300,300,-300,300);
}

// Ve hinh chu nhat va doan thang
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINE_LOOP); //Ve hinh vuong
   		glVertex2i(xmin,ymin);
   		glVertex2i(xmin,ymax);
   		glVertex2i(xmax,ymax);
   		glVertex2i(xmax,ymin);
   glEnd();
   
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);  //Ve duong thang
   		
   		glVertex2i(xdA,ydA);
   		glVertex2i(xdB,ydB);
   glEnd();

   glFlush();
}

int code(int xn,int yn)  //Tinh Code cua diem
{
    int c=0;
    if(yn>ymax)c=8;
    if(yn<ymin)c=4;
    if(xn>xmax)c=2;
    if(xn<xmin)c=1;
    return c;
}


void cohen_Line(int xA,int yA,int xB,int yB)
{
    int cA=code(xA,yA); // Code cua diem A
    int cB=code(xB,yB); // Code cua diem B
    float m=(yB-yA)/(xB-xA);
	while((cA|cB)>0)  
    {
    	//Truong Hop 1: Diem A va B nam cung phia
    	if((cA & cB)!=0){
    		break;
			exit(0);
			} 
    	//Truong hop 2: diem A hoac B nam trong cua so
		//Hoan doi A voi B
    	int xi=xA;
		int yi=yA;  // Lay toa do diem A
    	int c=cA;  
    	if(c==0){
			c=cB;
			xi=xB;
			yi=yB;
		}  
    	// Truong hop 3
    	// Tinh toa do cat voi cac canh hinh chu nhat
    	int x,y;
    	if((c & 8)){
			y=ymax;
			x=xi+ 1.0/m*(ymax-yi);
			}
    		else if((c & 4)){
				y=ymin;
				x=xi+1.0/m*(ymin-yi);
				}
      			else if((c & 2)){
			   		x=xmax;
					y=yi+m*(xmax-xi);
					}
       			  	else if((c & 1)){
						 x=xmin;
						 y=yi+m*(xmin-xi);
						 }
    
		//Cap nhat lai toa do diem A va B de ve lai doan thang
		//T?nh ma diem A va B
    	if(c==cA){ 
			xdA=x; 
			ydA=y;  
			cA=code(xdA,ydA); 
			}   
    	if(c==cB){ 
			xdB=x; 
			ydB=y;  
			cB=code(xdB,ydB); 
			}  
	}
// Ve lai hinh chu nhat v? doan thang da cat xen
 display();
}

void mykey(unsigned char key,int x,int y)
{
    if(key=='c')//Nhan phim c de xen (ve lai doan thang)
    { 
    	
        cohen_Line(xdA,ydA,xdB,ydB);
        glFlush();
    }
}
void MouseEventHandler(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		n++;
		P[n].x = x - 300;
		P[n].y = 300 - y;
		printf("\n n=%i x=%d y=%d", n, P[n].x, P[n].y);
		if (n%2!=0 && n!=0){
			glColor3f(0.0, 0.0, 0.0);
			xdA = P[(n - 1)].x;
   			ydA = P[(n - 1)].y;
   			xdB = P[n].x;
   			ydB = P[n].y;
			glFlush();
			glutPostRedisplay();
		}
	}
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);
    glutCreateWindow("DEMO XET DOAN THANG BANG HCN - Cohen - Sutherland");
    glutDisplayFunc(display);
    glutKeyboardFunc(mykey); //goi ham xu ly xu kien nhan phim
    glutMouseFunc(MouseEventHandler);
    initGL();
    glutMainLoop();
    return 0;
}

