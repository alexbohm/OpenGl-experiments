//#include <iostream>
//using namespace std;

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

double rotation;
static void display()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		glColor3f(0.01f,0.01f,0.01f);
		glVertex3f(0,0,0);
		glColor3f(1,1,1);
		glVertex3f(1,0,0);
		glColor3f(1,1,1);
		glVertex3f(0,0,1);
		
		glColor3f(0.01f,0.01f,0.01f);
		glVertex3f(0,0,0);
		glColor3f(1,1,1);
		glVertex3f(0,1,0);
		glColor3f(1,1,1);
		glVertex3f(0,0,1);
		
		glColor3f(0.01f,0.01f,0.01f);
		glVertex3f(0,0,0);
		glColor3f(1,1,1);
		glVertex3f(0,1,0);
		glColor3f(1,1,1);
		glVertex3f(1,0,0);
	glEnd();/*
	glBegin(GL_LINES);
		glColor3f(1,0,0);
		glVertex3f(0.8,0,0);
		glVertex3f(1,0,0);
	glEnd();*/
	glLoadIdentity();
	glRotated(-45,1,0,0);
	glRotated(rotation,0,1,0);
	glutSwapBuffers();
};
void mouseClick(int button, int state, int x, int y){
	if(!state) return;
	switch(button){
		case 3:
			rotation += 1.0;
			break;
		case 4:
			rotation -= 1.0;
			break;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Test");
	
	glutMouseFunc(mouseClick);
	glutDisplayFunc(display);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glutMainLoop();
	
	return 0;
}
