#include <iostream>
using namespace std;

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

double rotation;
static void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		glColor3f(0.1,0.1,0.1);
		glVertex3f(0,0,0);
		glColor3f(1,1,1);
		glVertex3f(1,0,0);
		glColor3f(1,1,1);
		glVertex3f(0,0,1);

		glColor3f(0.1,0.1,0.1);
		glVertex3f(0,0,0);
		glColor3f(1,1,1);
		glVertex3f(0,1,0);
		glColor3f(1,1,1);
		glVertex3f(0,0,1);

		glColor3f(0.1,0.1,0.1);
		glVertex3f(0,0,0);
		glColor3f(1,1,1);
		glVertex3f(0,1,0);
		glColor3f(1,1,1);
		glVertex3f(1,0,0);
	glEnd();
	glLoadIdentity();
	glRotated(45,1,0,0);
	glRotated(rotation,0,1,0);

	glutSwapBuffers();
};
void mouseClick(int button, int state, int x, int y){
	//cout<<"Clicked: "<<button<< " State: "<<state << " Location: "<<x<<':'<<y<<endl;
	if(button==3 && state==0){
		rotation += 2.0;
	}
	if(button==4 && state==0){
		rotation -= 2.0;
	}
	display();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glutCreateWindow("Test");

	glutDisplayFunc(display);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glutMouseFunc(mouseClick);
	
	glutMainLoop();
	
	return 0;
}
