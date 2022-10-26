#include <GL/Glut.h> 
#include <math.h>
#include <stdbool.h>
#include <cmath>
#include <iostream>
#define M_1_PI 3.1415926535
using namespace std;
void initGL()
{
	glClearColor(1.1f, 1.0f, 1.0f, 1.0f); 
	glOrtho(-320,320,-320,320,-1,1);	
}
float vertices[] = {100, 100, 0, 100, 0, 0, 100, 0, 50, 50};
void draw(void)
{
	glBegin(GL_POLYGON);
		glVertex2f(vertices[0], vertices[1]);
		glVertex2f(vertices[2], vertices[3]);
		glVertex2f(vertices[4], vertices[5]);
		glVertex2f(vertices[6], vertices[7]);
	glEnd();
	glFlush();
}
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, .5, .25);
	draw();
}
void rotate(float heso1)	//Doi xung qua tam hinh vuong (50,50)
{
	float x = vertices[8];
	float y = vertices[9];
	
	vertices[0] -= x; vertices[2] -= x; vertices[4] -= x; vertices[6] -= x; vertices[8] -= x;
	vertices[1] -= y; vertices[3] -= y; vertices[5] -= y; vertices[7] -= y; vertices[9] -= y;
	
	float heso;
	if (heso1>0) heso = 0.1;
	else heso = -0.1;
	for (float i=0;i<fabs(heso1);i+=0.1) {
	
		vertices[0]= vertices[0] * cos(heso*(M_1_PI/180)) - vertices[1] * sin(heso*(M_1_PI/180));
		vertices[2]= vertices[2] * cos(heso*(M_1_PI/180)) - vertices[3] * sin(heso*(M_1_PI/180));
		vertices[4]= vertices[4] * cos(heso*(M_1_PI/180)) - vertices[5] * sin(heso*(M_1_PI/180));
		vertices[6]= vertices[6] * cos(heso*(M_1_PI/180)) - vertices[7] * sin(heso*(M_1_PI/180));
	
		vertices[1]= vertices[0] * sin(heso*(M_1_PI/180))+ vertices[1] * cos(heso*(M_1_PI/180));
		vertices[3]= vertices[2] * sin(heso*(M_1_PI/180))+ vertices[3] * cos(heso*(M_1_PI/180));
		vertices[5]= vertices[4] * sin(heso*(M_1_PI/180))+ vertices[5] * cos(heso*(M_1_PI/180));
		vertices[7]= vertices[6] * sin(heso*(M_1_PI/180))+ vertices[7] * cos(heso*(M_1_PI/180));
	}
	vertices[0] += x; vertices[2] += x; vertices[4] += x; vertices[6] += x; vertices[8] += x;
	vertices[1] += y; vertices[3] += y; vertices[5] += y; vertices[7] += y; vertices[9] += y;
	

	draw();
}

void rotate_O(float heso)	//Doi xung qua goc toa do
{
	
	/* float heso1 = 5;
	for (float i=0;i<heso;i+=5) {
		vertices[0]= vertices[0] * cos((M_1_PI/180)) - vertices[1] * sin((M_1_PI/180));
		vertices[2]= vertices[2] * cos((M_1_PI/180)) - vertices[3] * sin((M_1_PI/180));
		vertices[4]= vertices[4] * cos((M_1_PI/180)) - vertices[5] * sin((M_1_PI/180));
		vertices[6]= vertices[6] * cos((M_1_PI/180)) - vertices[7] * sin((M_1_PI/180));
		vertices[8]= vertices[8] * cos((M_1_PI/180)) - vertices[9] * sin((M_1_PI/180));
	
		vertices[1]= vertices[0] * sin((M_1_PI/180)) + vertices[1] * cos((M_1_PI/180));
		vertices[3]= vertices[2] * sin((M_1_PI/180)) + vertices[3] * cos((M_1_PI/180));
		vertices[5]= vertices[4] * sin((M_1_PI/180)) + vertices[5] * cos((M_1_PI/180));
		vertices[7]= vertices[6] * sin((M_1_PI/180)) + vertices[7] * cos((M_1_PI/180));
		vertices[9]= vertices[8] * sin((M_1_PI/180)) + vertices[9] * cos((M_1_PI/180));
	} */
	float heso1;
	if (heso>0) heso1 = 0.1;
	else heso1 = -0.1;
	for (float i=0;i<fabs(heso);i+=0.1) {
		vertices[0]= vertices[0] * cos(heso1*(M_1_PI/180)) - vertices[1] * sin(heso1*(M_1_PI/180));
		vertices[2]= vertices[2] * cos(heso1*(M_1_PI/180)) - vertices[3] * sin(heso1*(M_1_PI/180));
		vertices[4]= vertices[4] * cos(heso1*(M_1_PI/180)) - vertices[5] * sin(heso1*(M_1_PI/180));
		vertices[6]= vertices[6] * cos(heso1*(M_1_PI/180)) - vertices[7] * sin(heso1*(M_1_PI/180));
		vertices[8]= vertices[8] * cos(heso1*(M_1_PI/180)) - vertices[9] * sin(heso1*(M_1_PI/180));
	
		vertices[1]= vertices[0] * sin(heso1*(M_1_PI/180))+ vertices[1] * cos(heso1*(M_1_PI/180));
		vertices[3]= vertices[2] * sin(heso1*(M_1_PI/180))+ vertices[3] * cos(heso1*(M_1_PI/180));
		vertices[5]= vertices[4] * sin(heso1*(M_1_PI/180))+ vertices[5] * cos(heso1*(M_1_PI/180));
		vertices[7]= vertices[6] * sin(heso1*(M_1_PI/180))+ vertices[7] * cos(heso1*(M_1_PI/180));
		vertices[9]= vertices[8] * sin(heso1*(M_1_PI/180))+ vertices[9] * cos(heso1*(M_1_PI/180));
	}

}


void changeX(float heso_tinh_tien)  //Tinh tien theo truc X
{
	vertices[0] += heso_tinh_tien;
	vertices[2] += heso_tinh_tien;
	vertices[4] += heso_tinh_tien;
	vertices[6] += heso_tinh_tien;
	vertices[8] += heso_tinh_tien;
}
void changeY(float heso_tinh_tien)  //Tinh tien theo truc Y
{
	vertices[1] += heso_tinh_tien;
	vertices[3] += heso_tinh_tien;
	vertices[5] += heso_tinh_tien;
	vertices[7] += heso_tinh_tien;
	vertices[9] += heso_tinh_tien;
}
void scale(float heso_ti_le) //Thay doi ti le qua tam hinh vuong (50,50)
{
	float x = vertices[8];
	float y = vertices[9];
	
	vertices[0] -= x; vertices[2] -= x; vertices[4] -= x; vertices[6] -= x; vertices[8] -= x;
	vertices[1] -= y; vertices[3] -= y; vertices[5] -= y; vertices[7] -= y; vertices[9] -= y;
	
	for(int i = 0 ; i < 8 ; i++) vertices[i] *= heso_ti_le;
	
	vertices[0] += x; vertices[2] += x; vertices[4] += x; vertices[6] += x; vertices[8] += x;
	vertices[1] += y; vertices[3] += y; vertices[5] += y; vertices[7] += y; vertices[9] += y;
	
	draw();	
}

void doiXung() {
	
	float a,b;
	float x1, y1, x2, y2;
	cout<<"TRUC DOI XUNG y = ax + b\nNhap a va b: ";
	cin>>a>>b;
	x1 = 0; y1 = b; x2 = 50; y2 = a*x2 + b;
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
	changeY(-b);
	
	float rt = atan(a)*180/M_1_PI;
	cout<<rt<<"\n";
	
	if (rt>=-45 && rt<=45) {
		if (y1!=y2) rotate_O(-rt);
		vertices[1] = -vertices[1]; 
		vertices[3] = -vertices[3]; 
		vertices[5] = -vertices[5]; 
		vertices[7] = -vertices[7]; 
		vertices[9] = -vertices[9];
		if (y1!=y2) rotate_O(rt);
	} else {
		rotate_O(90-rt);
		vertices[0] = -vertices[0]; 
		vertices[2] = -vertices[2]; 
		vertices[4] = -vertices[4]; 
		vertices[6] = -vertices[6]; 
		vertices[8] = -vertices[8];
		rotate_O(rt-90);
	}
	/* if (y1==y2) {
		vertices[1] = -vertices[1]; 
		vertices[3] = -vertices[3]; 
		vertices[5] = -vertices[5]; 
		vertices[7] = -vertices[7]; 
		vertices[9] = -vertices[9];
	} else if (rt>0) {
		float dx, dy;
		for (int i=0;i<10;i+=2) {
			float d = (float)abs(a*vertices[i]-vertices[i+1]+b)/sqrt((float)a*a+1);
			dx = d*sin(rt);
			dy = d*cos(rt);
			if (vertices[i+1]-(a*vertices[i]+b)>0) {
				vertices[i] += 2*dx;
				vertices[i+1] -= 2*dy;
			} else {
				vertices[i] -= 2*dx;
				vertices[i+1] += 2*dy;
			}
		}
	} else {
		rt = -rt;
		float dx, dy;
		for (int i=0;i<10;i+=2) {
			float d = (float)abs(a*vertices[i]-vertices[i+1]+b)/sqrt((float)a*a+1);
			dx = d*sin(rt);
			dy = d*cos(rt);
			if (vertices[i+1]-(a*vertices[i]+b)>0) {
				vertices[i] -= 2*dx;
				vertices[i+1] -= 2*dy;
			} else {
				vertices[i] += 2*dx;
				vertices[i+1] += 2*dy;
			}
		}
	} */	
	
	changeY(b);
	
	
}

void keyPressed(unsigned char key, int x, int y) {
	
	switch (key)
	{
	case 'T':       //Nhan phim T hoac t tang kich thuoc
	case 't':
		scale(1.2);
		break;

	case 'N':       //Nhan phim N hoac n giam kich thuoc
	case 'n':
		scale(0.8);
		break;

	case 'L':       //Nhan phim L hoac l xoay trái
	case 'l':
		rotate(-5);
		//draw();
		break;

	case 'R':      //Nhan phim R hoac r xoay phai
	case 'r':
		rotate(5);
		//draw();
		break;
		
	case 'S':       //Nhan phim S hoac s doi xung qua y = ax + b
	case 's':
		doiXung();
		draw();
		break;
	}
}
void keypressSpecial(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {changeY(10);draw();}    //Phim mui ten di len
	if (key == GLUT_KEY_DOWN) {changeY(-10);draw();} //Phim mui ten di xuong
	if (key == GLUT_KEY_RIGHT) {changeX(10);draw();} //Phim mui ten sang phai
	if (key == GLUT_KEY_LEFT) {changeX(-10);draw();} //Phim mui ten sang trai
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);    
	glutInitWindowPosition(900, 50); 
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutCreateWindow("Transform 2D"); 
    initGL();
    
	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutSpecialFunc(keypressSpecial);
	glutKeyboardFunc(keyPressed);  
	glutMainLoop(); 
}


