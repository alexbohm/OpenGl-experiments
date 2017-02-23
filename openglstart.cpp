#include <iostream>
//#include <GL/freeglut.h>
#include <GL/glut.h>
//#include <Gl/glu>
using namespace std;
double rotation;
static void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin (GL_LINES);
        glColor3f (1,0,0);
        glVertex3f (0,0,0);
        glVertex3f (1,0,0);
         
        glColor3f (0,0,1);
        glVertex3f (0,0,0);
        glVertex3f (0,0,1);

        glColor3f (1,1,1);
        glVertex3f (0,0,1);
        glVertex3f (1,0,0);

        glColor3f (0,1,0);
        glVertex3f (0,0,0);
        glVertex3f (0,1,0);
    glEnd();
    glLoadIdentity();
    glRotated(45,1,0,0);
    glRotated(rotation,0,1,0);
    /*glBegin(GL_QUADS);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(0.0f,1.0f,0.0f);
        glVertex3f(1.0f,1.0f,1.0f);
        glVertex3f(1.0f,0.0f,1.0f);
    glEnd();*/

    glutSwapBuffers();
    //cout<<"buff switch"<<endl;
};
void mouseClick(int button, int state, int x, int y){
    //cout<<"Clicked: "<<button<< " State: "<<state << " Location: "<<x<<':'<<y<<endl;
    if(button==3 && state==0){
        //cout<<"Rotated Right"<<endl;
        rotation += 2.0;
    }
    if(button==4 && state==0){
        //cout<<"Rotated Left"<<endl;
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
    glutCreateWindow("Test");

    glutDisplayFunc(display);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMouseFunc(mouseClick);
    glutMainLoop();
    
    return 0;
}
