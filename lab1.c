#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//Green
    glVertex2f(0.2,0.2);
    glVertex2f(0.4,0.6);
    glVertex2f(0.6,0.2);
    
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);//Green
    for(int i=0;i <360;i++){
      double angle= i * 3.14/180;
      glVertex2f((1.0 + 0.3 * sin(angle)),(0.4 + 0.3 * cos(angle)));
    }
    
    glEnd();
    glFlush();
}
int main(int argc , char** argv){
    glutInit(&argc , argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
      glutCreateWindow("frame1");
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,2.0,0.0,2.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}