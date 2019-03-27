#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

void init() {
	gluOrtho2D(-500, 500, -500, 500);
}
void circle(int r,int x1,int y1){
	glBegin(GL_TRIANGLE_FAN);
	for (int i=1;i<360;i++)
	{
	    int x = r*cos(i)+x1;
	    int y = r*sin(i)+y1;
	    glVertex2f(x,y);
	}

	glEnd();
	glFlush();
}
void drawPlates(){
	glColor3f(1,1,1);//plate1
	circle(55,0,220);
	
	glColor3f(1,1,1);//plate2
	circle(55,220,60);
	
	glColor3f(1,1,1);//plate3
	circle(55,-220,60);
	
	glColor3f(1,1,1);//plate4
	circle(55,130,-190);
	
	glColor3f(1,1,1);//plate5
	circle(55,-130,-190);
	
}
void DrawEllipse(int r1,int r2,int x1,int y1,int angle)
{
       	glBegin(GL_TRIANGLE_FAN);
        for(int t = 0; t <= 360; t +=1)
	{
          int x = (r1*sin(t)-r2*cos(t+(angle*3.14/180)))+x1;
	  int y = (r2*cos(t))+y1;
	  glVertex2f(x,y);
       }
       glEnd();
       glFlush();
}
void drawPhilosopher(){
	glColor3f(1,0,0);
	DrawEllipse(20,50,200,300,45);
	//DrawEllipse(20,50,21,320);
	
	//circle(40,0,370);
	
}
void display() {
	glClearColor(0.85155,0.85155,0.6, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	
	drawPhilosopher();
	glColor3f(0.62,0.37,0.26);//table
	circle(300,0,0);
	
	drawPlates();
	
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3d");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
